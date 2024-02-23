#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct sData
{
	int key;
	int priority;
};

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int printNum, targetIndex;
		cin >> printNum >> targetIndex;

		// key : index
		// value : priority
		queue< sData> q;
		vector<int> priorityNumber;
		for (int j = 0; j < printNum; ++j)
		{
			sData tempData;
			tempData.key = j;
			cin >> tempData.priority;
			priorityNumber.push_back(tempData.priority);
			q.push(tempData);
		}

		sort(priorityNumber.begin(), priorityNumber.end(), greater<int>());

		// Do it!
		int count = 1;
		int maxPriorityIndex = 0;
		while (!q.empty())
		{
			sData frontData = q.front();
			if (frontData.priority == priorityNumber[maxPriorityIndex])
			{
				maxPriorityIndex++;
				if (frontData.key == targetIndex)
				{
					cout << count << '\n';
					break;
				}
				count++;
			}

			q.push(frontData);
			q.pop();
		}
	}
	return 0;
}