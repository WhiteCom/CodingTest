#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int testCase, targetCost;
	cin >> testCase >> targetCost;

	// 동전 가짓수 체크
	map<int, bool> costContainer;

	for (int i = 0; i < testCase; ++i)
	{
		int cost;
		cin >> cost;
		costContainer[cost] = true;
	}

	int count = 0;
	// last Index
	map<int, bool>::iterator it = --costContainer.end();
	while (it != costContainer.begin())
	{
		int curUsableCost = it->first;
		if (curUsableCost <= targetCost)
		{
			int curCount = targetCost / curUsableCost;
			targetCost -= curUsableCost * curCount;
			count += curCount;
		}
			
		--it;
	}

	// 마지막 begin일 때 처리 필요
	if (targetCost > 0)
	{
		int curUsableCost = costContainer.begin()->first;
		int curCount = targetCost / curUsableCost;
		targetCost -= curUsableCost * curCount;
		count += curCount;
	}

	cout << count << '\n';

	return 0;
}