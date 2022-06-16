#include "TTreeTable.h"
#include <iostream>
void TTreeTable::PrintRec(std::ostream& os) const
{
	PrintNode(os, pRoot, 0);
}
TTreeTable::TTreeTable() = default;
TTreeTable::~TTreeTable() { DelTree(pRoot); }
void TTreeTable::DelTree(TNode * p)
{
	if (p)
	{
		DelTree(p->pLeft);
		DelTree(p->pRight);
		delete p;
	}
}
bool TTreeTable::Find(TKey key) const
{
	pCurr = pRoot;
	pPrev = nullptr;
	while (pCurr != nullptr)
	{
		++eff;
		if (pCurr->rec.key == key)
		{
			return true;
		}
		pPrev = pCurr;
		if (pCurr->rec.key > key)
		{
			pCurr = pCurr->pLeft;
		}
		else
		{
			pCurr = pCurr->pRight;
		}
	}
	pCurr = pPrev;
	return false;
}
bool TTreeTable::Insert(TRecord rec)
{
	if (Find(rec.key))
		return false;
	TNode* tmp = new TNode(rec);
	++eff;
	++dataCount;
	if (pCurr == nullptr)
	{
		pRoot = tmp;
	}
	else
	{
		if (rec.key > pCurr->rec.key)
			pCurr->pRight = tmp;
		else
			pCurr->pLeft = tmp;
	}
	return true;
}
bool TTreeTable::Delete(TKey key)
{
	if (IsEmpty() || !Find(key))
		return false;
	TNode* tmp = pCurr;
	if (pCurr->pRight == nullptr)
	{
		if (pPrev == nullptr)
			pRoot = pCurr->pLeft;
		if (pCurr->rec.key > pPrev->rec.key)
			pPrev->pRight = pCurr->pLeft;
		else
			pPrev->pLeft = pCurr->pLeft;
	}
	else if (pCurr->pLeft == nullptr)
	{
		if (pPrev == nullptr)
			pRoot = pCurr->pRight;
		if (pCurr->rec.key > pPrev->rec.key)
			pPrev->pRight = pCurr->pRight;
		else
			pPrev->pLeft = pCurr->pRight;
	}
	else
	{
		tmp = tmp->pLeft;
		pPrev = pCurr;
		while (tmp->pRight != nullptr)
		{
			++eff;
			pPrev = tmp;
			tmp = tmp->pRight;
		}
		pCurr->rec = tmp->rec;
		if (pCurr->pLeft == tmp)
			pPrev->pLeft = tmp->pLeft;
		else
			pPrev->pRight = tmp->pLeft;
		delete tmp;
	}
	--dataCount;
	++eff;
	return true;
}
void TTreeTable::Reset() const
{
	currPos = 0;
	pCurr = pRoot;
	st = std::stack<TNode*>();
	if (pCurr)
	{
		while (pCurr->pLeft)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
	}
	st.push(pCurr);
}
void TTreeTable::GoNext() const
{
	pCurr = st.top();
	st.pop();
	if (pCurr)
	{
		if (pCurr->pRight)
		{
			pCurr = pCurr->pRight;
			while (pCurr->pLeft)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			st.push(pCurr);
		}
		else
		{
			if (!st.empty())
			{
				pCurr = st.top();
			}
		}
		currPos++;
	}
}
bool TTreeTable::IsEnd() const { return currPos == dataCount; }
const TRecord& TTreeTable::GetCurrentRecord() const
{
	if (pCurr)
	{
		return pCurr->rec;
	}
	else
	{
		throw std::exception("Table is empty\n");
	}
}
void TTreeTable::PrintNode(std::ostream & os, const TNode * p, int level)
{
	if (p)
	{
		for (int i = 0; i < level; ++i)
		{
			os << ' ';
		}
		os << p->rec.key << "\r\n";
		PrintNode(os, p->pLeft, level + 1);
		PrintNode(os, p->pRight, level + 1);
	}
}
