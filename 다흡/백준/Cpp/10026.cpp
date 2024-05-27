#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int BFS_RedGreen(vector< vector<char>>& graph, vector< vector<bool>>& visited, int startY, int startX)
{
	queue< pair<int, int>> q;
	q.push({startY, startX});
	visited[startY][startX] = true;

	int maxY = graph.size();
	int maxX = graph[0].size();

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	char curColor = graph[startY][startX];

	int result = 0;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			// 범위 체크
			if (nextY < 0 || nextY >= maxY)
				continue;

			if (nextX < 0 || nextX >= maxX)
				continue;

			// 방문여부 체크
			if (visited[nextY][nextX] == true)
				continue;

			// 동일색상 체크
			// 적록색약이라, R, G는 같은색상으로 취급
			if (curColor == 'R' || curColor == 'G')
			{
				if (graph[nextY][nextX] == 'R' || graph[nextY][nextX] == 'G')
				{
					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}
			else
			{
				// 파랑
				if (curColor == graph[nextY][nextX])
				{
					visited[nextY][nextX] = true;
					q.push({ nextY, nextX });
				}
			}

		}
	}

	result++;
	
	return result;
}

int BFS_Normal(vector< vector<char>>& graph, vector< vector<bool>>& visited, int startY, int startX)
{
	queue< pair<int, int>> q;
	q.push({ startY, startX });
	visited[startY][startX] = true;

	int maxY = graph.size();
	int maxX = graph[0].size();

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	char curColor = graph[startY][startX];

	int result = 0;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			// 범위 체크
			if (nextY < 0 || nextY >= maxY)
				continue;

			if (nextX < 0 || nextX >= maxX)
				continue;

			// 방문여부 체크
			if (visited[nextY][nextX] == true)
				continue;

			// 동일색상 체크
			if (graph[nextY][nextX] == curColor)
			{
				visited[nextY][nextX] = true;
				q.push({ nextY, nextX });
			}
		}
	}

	result++;

	return result;
}

int main()
{
	int graphSize;
	cin >> graphSize;

	vector<string> input(graphSize);

	cin.ignore();
	for (int i = 0; i < graphSize; ++i)
	{
		getline(cin, input[i]);
	}

	vector< vector<char>> graph(graphSize, vector<char>(graphSize, '0'));

	for (int i = 0; i < graphSize; ++i)
	{
		for (int j = 0; j < graphSize; ++j)
		{
			graph[i][j] = input[i][j];
		}
	}

	vector< vector<bool>> red_green_visited(graphSize, vector<bool>(graphSize, false));
	vector< vector<bool>> normal_visited(graphSize, vector<bool>(graphSize, false));

	// Red-Green
	int red_green_reuslt = 0;
	int normal_result = 0;

	for (int i = 0; i < graphSize; ++i)
	{
		for (int j = 0; j < graphSize; ++j)
		{
			if(red_green_visited[j][i] == false)
				red_green_reuslt += BFS_RedGreen(graph, red_green_visited, j, i);
			if(normal_visited[j][i] == false)
				normal_result += BFS_Normal(graph, normal_visited, j, i);
		}
	}

	cout << normal_result << " " << red_green_reuslt << '\n';

	return 0;
}