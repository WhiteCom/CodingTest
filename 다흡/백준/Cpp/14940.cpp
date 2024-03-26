#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct sPos
{
	int x, y;
};

// ��ǥ�������κ��� ��� ������ ���� �Ÿ� ��ȯ
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

	// �� ������ �Ÿ����� (�����)
	vector< vector<int>> distance(maxY, vector<int>(maxX, 0));
	// �湮����
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

			// ���� üũ
			// ���� ������ ���� �ƴѰ�� �Ÿ� ���� �� ť ����
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

	// ���� ��� ���� �湮�ߴ��� ���캸��
	for (int i = 0; i < maxY; ++i)
	{
		for (int j = 0; j < maxX; ++j)
		{
			// ���ߵǴ� �����ε�, �湮 ���Ѱ�� �Ÿ�����
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
			// ��ǥ�������� ���� �ƴ� �����ǥ���� �Ÿ����
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