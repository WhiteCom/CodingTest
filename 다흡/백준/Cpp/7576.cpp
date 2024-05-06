#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 1000000
#define min(a, b) (a) < (b) ? (a) : (b)

using namespace std;

struct posData
{
	int y, x;
};

void BFS(queue<posData>& q, vector< vector<int>>& graph)
{
	int maxRow = graph.size();
	int maxCol = graph[0].size();

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	posData pos = q.front();

	while (!q.empty())
	{
		posData sPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			posData nextPos;
			nextPos.y = sPos.y + dy[i];
			nextPos.x = sPos.x + dx[i];

			// 범위 체크
			if (nextPos.y < 0 || nextPos.y >= maxRow)
				continue;

			if (nextPos.x < 0 || nextPos.x >= maxCol)
				continue;

			if (graph[nextPos.y][nextPos.x] == 0)
			{
				graph[nextPos.y][nextPos.x] = graph[sPos.y][sPos.x] + 1;
				q.push(nextPos);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int row, col;
	cin >> col >> row;

	vector< vector<int>> graph(row, vector<int>(col, 0));
	queue<posData> q;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> graph[i][j];
			
			if (graph[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	// Calculate
	BFS(q, graph);

	// Result
	int result = 0;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (graph[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}

			result = result > graph[i][j] ? result : graph[i][j];
		}
	}

	cout << result - 1 << '\n';

	return 0;
}