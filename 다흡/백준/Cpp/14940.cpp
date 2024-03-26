#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct sPos
{
	int x, y;
};

// 목표지점으로부터 모든 지점에 대한 거리 반환
vector< vector<int>> BFS(vector< vector<int>>& graph, int startY, int startX)
{
	int maxY = graph.size();
	int maxX = graph[0].size();

	queue<sPos> q;
	sPos start;
	start.x = startX;
	start.y = startY;
	q.push(start);

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	// 각 정점별 거리정보 (결과값)
	vector< vector<int>> distance(maxY, vector<int>(maxX, 0));
	// 방문여부
	vector< vector<bool>> visited(maxY, vector<bool>(maxX, false));

	visited[start.y][start.x] = true;

	while (!q.empty())
	{
		sPos startPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			sPos nextPos;
			nextPos.x = startPos.x + dx[i];
			nextPos.y = startPos.y + dy[i];

			// 범위 체크
			// 다음 정점이 벽이 아닌경우 거리 갱신 및 큐 삽입
			if (0 <= nextPos.x && nextPos.x < maxX
				&& 0 <= nextPos.y && nextPos.y < maxY
				&& visited[nextPos.y][nextPos.x] == false
				&& graph[nextPos.y][nextPos.x] == 1)
			{
				visited[nextPos.y][nextPos.x] = true;
				distance[nextPos.y][nextPos.x] = distance[startPos.y][startPos.x] + 1;
				q.push(nextPos);
			}
		}
	}

	// 정말 모든 정점 방문했는지 살펴보기
	for (int i = 0; i < maxY; ++i)
	{
		for (int j = 0; j < maxX; ++j)
		{
			// 가야되는 지점인데, 방문 못한경우 거리갱신
			if (graph[i][j] == 1 && visited[i][j] == false)
				distance[i][j] = -1;
		}
	}

	return distance;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int row, col;
	cin >> row >> col;

	vector< vector<int>> graph(row, vector<int>(col, 0));
	vector< vector<int>> distance;

	// Init
	// 2 : Destination
	// 1 : Ground
	// 0 : Wall
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> graph[i][j];
		}
	}

	// Calculate
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			// 목표지점에서 벽이 아닌 모든좌표들의 거리계산
			if (graph[i][j] == 2)
			{
				distance = BFS(graph, i, j);
			}
		}
	}

	// Result Print
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << distance[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}