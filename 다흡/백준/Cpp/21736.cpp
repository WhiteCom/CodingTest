#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct posData
{
	int y, x;
};

int BFS(vector<string>& graph, int startY, int startX)
{
	int maxRow = graph.size();
	int maxCol = graph[0].length();

	vector< vector<bool>> visited(maxRow, vector<bool>(maxCol, false));

	queue<posData> q;
	q.push({ startY, startX });
	visited[startY][startX] = true;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int result = 0;

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
			if (nextPos.x < 0 || nextPos.x >= maxCol)
				continue;

			if (nextPos.y < 0 || nextPos.y >= maxRow)
				continue;

			// 이동 가능여부 체크
			if (graph[nextPos.y][nextPos.x] == 'X' || visited[nextPos.y][nextPos.x] == true)
				continue;

			if (graph[nextPos.y][nextPos.x] == 'P')
				result++;

			visited[nextPos.y][nextPos.x] = true;
			q.push(nextPos);
		}
	}

	return result;
}

int main()
{
	int row, col;
	cin >> row >> col;

	vector<string> graph(row, "");

	int startX = 0, startY = 0;
	for (int i = 0; i < row; ++i)
	{
		cin >> graph[i];
		
		for (int j = 0; j < graph[i].length(); ++j)
		{
			if (graph[i][j] == 'I')
			{
				startX = j;
				startY = i;
			}
		}
	}

	int result = BFS(graph, startY, startX);

	if (result == 0)
		cout << "TT\n";
	else
		cout << result << '\n';

 	return 0;
}