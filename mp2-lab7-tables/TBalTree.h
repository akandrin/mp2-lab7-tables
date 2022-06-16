#pragma once
#include "TTreeTable.h"
#include <cassert>
class TBalTree : public TTreeTable
{
	static int height(TNode* p)
	{
		return p != nullptr ? p->mHeight : 0;
	}
	static int bfactor(TNode* p)
	{
		assert(p != nullptr);
		return height(p->pRight) - height(p->pLeft);
	}
	static void fixheight(TNode* p)
	{
		int hl = height(p->pLeft);
		int hr = height(p->pRight);
		p->mHeight = (hl > hr ? hl : hr) + 1;
	}
	static TNode* rotateRight(TNode* p)
	{
		TNode* q = p->pLeft;
		p->pLeft = q->pRight;
		q->pRight = p;
		fixheight(p);
		fixheight(q);
		return q;
	}
	static TNode* rotateLeft(TNode* q)
	{
		TNode* p = q->pRight;
		q->pRight = p->pLeft;
		p->pLeft = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	static TNode* balance(TNode* p)
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->pRight) < 0)
				p->pRight = rotateRight(p->pRight);
			return rotateLeft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->pLeft) > 0)
				p->pLeft = rotateLeft(p->pLeft);
			return rotateRight(p);
		}
		return p;
	}
	TNode* insert(TNode* p, TRecord rec)
	{
		++eff;
		if (p == nullptr)
		{
			operationResult = true;
			return new TNode(rec);
		}
		if (rec.key < p->rec.key)
			p->pLeft = insert(p->pLeft, rec);
		else if (rec.key > p->rec.key)
			p->pRight = insert(p->pRight, rec);
		else
			return p;
		return balance(p);
	}
	TNode* findMin(TNode* p)
	{
		++eff;
		return p->pLeft ? findMin(p->pLeft) : p;
	}
	TNode* removeMin(TNode* p)
	{
		++eff;
		if (p->pLeft == 0)
			return p->pRight;
		p->pLeft = removeMin(p->pLeft);
		return balance(p);
	}
	TNode* remove(TNode* p, TKey k)
	{
		++eff;
		if (p == nullptr) return 0;
		if (k < p->rec.key)
			p->pLeft = remove(p->pLeft, k);
		else if (k > p->rec.key)
			p->pRight = remove(p->pRight, k);
		else //  k == p->rec.key 
		{
			TNode* q = p->pLeft;
			TNode* r = p->pRight;
			delete p;
			operationResult = true;
			if (!r)
				return q;
			TNode* min = findMin(r);
			min->pRight = removeMin(r);
			min->pLeft = q;
			return balance(min);
		}
		return balance(p);
	}

	bool operationResult;

public:
	bool Insert(TRecord rec)
	{
		operationResult = false;
		pRoot = insert(pRoot, rec);
		if (operationResult)
			++dataCount;
		return operationResult;
	}
	bool Delete(TKey key)
	{
		operationResult = false;
		pRoot = remove(pRoot, key);
		if (operationResult)
			--dataCount;
		return operationResult;
	}
};
