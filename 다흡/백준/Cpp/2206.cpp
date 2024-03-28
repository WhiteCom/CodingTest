#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define MAX_DISTANCE 1000000

using namespace std;

struct sData
{
	int x, y;
	int value;
};

struct posData
{
	int x, y;
	int wall;
	int count;
};

int BFS(vector< vector<sData>>& graph, vector< vector< vector<bool>>>& visited, int targetY, int targetX)
{
	int maxY = graph.size();
	int maxX = graph[0].size();

	posData startPos;
	startPos.x = 0;
	startPos.y = 0;
	startPos.wall = 0;
	startPos.count = 1;

	queue<posData> q;
	q.push(startPos);

	visited[0][startPos.y][startPos.x] = true;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	// 방문하면서 목표지점까지 도달하는데 거리(distance)를 갱신해줘야함.
	// 벽을 부수고 왔는지 여부에 따라 어떤 계층의 2차원 맵을 갱신해줘야 할 지 달라짐.
	while (!q.empty())
	{
		posData sPos = q.front();

		int curWall = sPos.wall;
		int curCount = sPos.count;

		q.pop();

		if (sPos.y == targetY && sPos.x == targetX)
		{
			return curCount;
		}
		 
		for (int i = 0; i < 4; ++i)
		{
			posData nextPos;
			nextPos.y = sPos.y + dy[i];
			nextPos.x = sPos.x + dx[i];
			nextPos.count = curCount + 1;
			
			// 범위 체크, 현재 좌표 방문여부
			if (0 <= nextPos.x && nextPos.x < maxX
				&& 0 <= nextPos.y && nextPos.y < maxY
				&& visited[curWall][nextPos.y][nextPos.x] == false)
			{
				// 벽이 없는경우
				if (graph[nextPos.y][nextPos.x].value == 0)
				{
					visited[curWall][nextPos.y][nextPos.x] = true;
					nextPos.wall = curWall;
					q.push(nextPos);
				}

				// 벽이 있는경우, 아직 안 뚫은 경우
				else if (graph[nextPos.y][nextPos.x].value == 1 && curWall == 0)
				{
					visited[curWall + 1][nextPos.y][nextPos.x] = true;
					nextPos.wall = curWall + 1;
					q.push(nextPos);
				}
			}
		}
	}

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

	vector< vector<sData>> graph(row, vector<sData>(col, { 0, 0, 0 }));
	vector< vector< vector<bool>>> visited(2, vector< vector<bool>>(row, vector<bool>(col, false)));

	// Convert String to Int 
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			graph[i][j].value = inputData[i][j] - '0';
		}
	}

	

	int result = 0;
	result = BFS(graph, visited, row - 1, col - 1);

	cout << result << '\n';

	return 0;
}