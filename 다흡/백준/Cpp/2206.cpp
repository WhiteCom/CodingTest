#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct posData
{
	int x, y;
	int wall;
	int count;
};

int BFS(vector< vector<int>>& graph, vector< vector< vector<bool>>>& visited, int targetY, int targetX)
{
	int maxY = graph.size();
	int maxX = graph[0].size();

	queue<posData> q;
	posData startPos;
	startPos.x = 0;
	startPos.y = 0;
	startPos.wall = 0;
	startPos.count = 1;

	q.push(startPos);

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	while (!q.empty())
	{
		posData sPos;
		sPos = q.front();
		
		q.pop();

		if (sPos.x == targetX && sPos.y == targetY)
		{
			return sPos.count;
		}

		for (int i = 0; i < 4; ++i)
		{
			posData nextPos;
			nextPos.x = sPos.x + dx[i];
			nextPos.y = sPos.y + dy[i];
			nextPos.wall = sPos.wall;
			nextPos.count = sPos.count;

			// 범위 체크, 방문여부 체크
			if (0 <= nextPos.x && nextPos.x < maxX
				&& 0 <= nextPos.y && nextPos.y < maxY
				&& visited[nextPos.wall][nextPos.y][nextPos.x] == false)
			{
				// 벽 아닌경우
				if (graph[nextPos.y][nextPos.x] == 0)
				{
					nextPos.count += 1;
					visited[nextPos.wall][nextPos.y][nextPos.x] = true;
					q.push(nextPos);
				}

				// 벽 인경우 + 이전에 벽 뚫고왔는지 체크
				if (graph[nextPos.y][nextPos.x] == 1 && nextPos.wall == 0)
				{
					nextPos.wall += 1;
					nextPos.count += 1;
					visited[nextPos.wall][nextPos.y][nextPos.x] = true;
					q.push(nextPos);
				}
			}
		}
	}
	
	// 도착지점에 도달하지 못한 경우, -1 반환
	return -1;
}

int main()
{
	int row, col;
	cin >> row >> col;

	vector<string> inputData(row, "");
	for (int i = 0; i < row; ++i)
	{
		cin >> inputData[i];
	}

	// Convert String to Int
	vector< vector<int>> graph(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			graph[i][j] = inputData[i][j] - '0';
		}
	}

	vector< vector< vector<bool>>> visited(2, vector< vector<bool>>(row, vector<bool>(col, false)));

	int result = BFS(graph, visited, row - 1, col - 1);
	cout << result << '\n';

	return 0;
}