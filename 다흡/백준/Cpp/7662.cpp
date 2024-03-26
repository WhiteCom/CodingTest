#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
	// 입출력 시간단축용
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		map<int, int> data;
		priority_queue<int, vector<int>, greater<int>> pq_min; // 최소값
		priority_queue<int, vector<int>, less<int>> pq_max; // 최대값

		int num;
		cin >> num;

		// Calculate
		for (int j = 0; j < num; ++j)
		{
			char command;
			int num;

			cin >> command >> num;

			if (command == 'I')
			{
				pq_max.push(num);
				pq_min.push(num);
				data[num]++;
			}
			else if (command == 'D' && num == 1)
			{
				// 최대값 삭제
				if (!pq_max.empty())
				{
					int top_greater = pq_max.top();
					pq_max.pop();
					data[top_greater]--;
				}

				// 반대쪽도 해당값이 남아있지 않도록 삭제
				while (!pq_min.empty() && data[pq_min.top()] == 0)
				{
					pq_min.pop();
				}
				// 반대쪽도 해당값이 남아있지 않도록 삭제
				while (!pq_max.empty() && data[pq_max.top()] == 0)
				{
					pq_max.pop();
				}
			}
			else if (command == 'D' && num == -1)
			{
				// 최소값 삭제
				if (!pq_min.empty())
				{
					int top_less = pq_min.top();
					pq_min.pop();
					data[top_less]--;
				}

				// 반대쪽도 해당값이 남아있지 않도록 삭제
				while (!pq_min.empty() && data[pq_min.top()] == 0)
				{
					pq_min.pop();
				}
				// 반대쪽도 해당값이 남아있지 않도록 삭제
				while (!pq_max.empty() && data[pq_max.top()] == 0)
				{
					pq_max.pop();
				}
			}
		}

		// Result
		if (pq_max.empty() && pq_min.empty())
			cout << "EMPTY\n";
		else
		{
			cout << pq_max.top() << " " << pq_min.top() << '\n';
		}
		
	}
	return 0;
}