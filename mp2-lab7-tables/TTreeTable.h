#pragma once
#include <stack>
#include "TTable.h"
struct TNode
{
	TRecord rec;
	TNode* pLeft, * pRight;
	int mHeight = 1;
	TNode(TRecord rec) : rec(rec), pLeft(nullptr), pRight(nullptr) {}
};

class TTreeTable : public TTable
{
	mutable int currPos = 0;
	int GetSize() const override { return -1; }
	static void PrintNode(std::ostream& os, const TNode* p, int level);
protected:
	mutable TNode* pRoot = nullptr, * pCurr = nullptr, * pPrev = nullptr;
	mutable std::stack<TNode*> st;
	void PrintRec(std::ostream& os) const override;
public:
	TTreeTable();
	~TTreeTable();
	void DelTree(TNode* p);
	bool Find(TKey) const override;
	bool Insert(TRecord) override;
	bool Delete(TKey) override;
	void Reset() const override;
	void GoNext() const override;
	bool IsFull() const override { return false; }
	bool IsEnd() const override;
	const TRecord& GetCurrentRecord() const override;
public:
	TNode* GetRoot() const { return pRoot; }
};

