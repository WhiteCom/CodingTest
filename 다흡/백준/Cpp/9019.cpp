#include <iostream>
#include <queue>
#include <string>

using namespace std;

void BFS(int startNum, int targetNum)
{
	bool visited[10000] = {};
	visited[startNum] = true;

	// pair대신, struct 로 하게되면 시간초과 발생함...
	queue< pair<string, int>> q;
	q.push({"", startNum});

	while (!q.empty())
	{
		pair<string, int> start = q.front();
		string command = start.first;
		int num = start.second;
		q.pop();

		if (num == targetNum)
		{
			cout << command << '\n';
			break;
		}

		// 1. D
		int D_num = num * 2 % 10000;
		string D_command = command + "D";
		if (visited[D_num] == false)
		{
			visited[D_num] = true;
			q.push({D_command, D_num});
		}

		// 2. S
		int S_num = (num == 0 ? 9999 : num - 1);
		string S_command = command + "S";
		if (visited[S_num] == false)
		{
			visited[S_num] = true;
			q.push({S_command, S_num});
		}

		// 3. L
		int L_num = (num % 1000) * 10 + (num / 1000);
		string L_command = command + "L";
		if (visited[L_num] == false)
		{
			visited[L_num] = true;
			q.push({L_command, L_num});
		}

		// 4. R
		int R_num = (num % 10 * 1000) + (num / 10);
		string R_command = command + "R";
		if (visited[R_num] == false)
		{
			visited[R_num] = true;
			q.push({R_command, R_num});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;

	int startNum, targetNum;
	for (int i = 0; i < testCase; ++i)
	{
		cin >> startNum >> targetNum;
		BFS(startNum, targetNum);
	}
	return 0;
}