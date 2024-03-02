#include <iostream>
#include <queue>

using namespace std;

int calculate(queue< pair<int, int>>& printQueue, int target, vector<int>& priorityArr)
{
	// Process printQueue
	int count = 1;
	int lastOffset = 1;
	while (!printQueue.empty())
	{
		int curPriority = printQueue.front().first;
		int curIndex = printQueue.front().second;
		int last = priorityArr.size() - lastOffset;
		int maxPriority = priorityArr[last];

		if (curIndex == target && curPriority >= maxPriority)
			return count;
		else if (curPriority >= maxPriority)
		{
			printQueue.pop();
			lastOffset++;
			count++;
		}
		else
		{
			printQueue.push({curPriority, curIndex});
			printQueue.pop();
		}
	}

	return count;
 }

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int n, findIndex;
		cin >> n >> findIndex;
		queue< pair<int, int>> printQueue; // first : priority, second : index
		vector<int> priorityArr;
		for (int j = 0; j < n; ++j)
		{
			int priority;
			cin >> priority;
			printQueue.push({ priority, j });
			priorityArr.push_back(priority);
		}

		sort(priorityArr.begin(), priorityArr.end());

		cout << calculate(printQueue, findIndex, priorityArr) << '\n';
	}
	return 0;
}