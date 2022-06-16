#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TTreeTable.h"
#include "TBalTree.h"
#include <cassert>
#include <iostream>
#include "RandomRange.h"
int main1()
{
	TArrayHash table(10);
	RandomRange<int> randomRange(1, 10, NextValue<int>{});
	for (; randomRange.HasNext(); )
	{
		table.Insert(randomRange.GetNext());
	}

	std::cout << table;
	table.Delete(9);
	std::cout << table;
	table.Delete(8);

	std::cout << table;
	return 0;
}
