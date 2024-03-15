#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int>> StringGrpahToInt(vector<string>& strGraph, int graphSize)
{
	vector< vector<int>> graph(graphSize, vector<int>(graphSize, 0));

	for (int i = 0; i < graphSize; ++i)
	{
		for (int j = 0; j < graphSize; ++j)
		{
			graph[i][j] = strGraph[i][j] - '0';
		}
	}

	return graph;
}

// 한 단지 내에 있는 집의 수를 반환
int BFS(vector< vector<int>>& graph, vector< vector<bool>>& visited, int startRow, int startCol)
{
	int homeCount = 0;

	queue< pair<int, int>> q;
	q.push({ startRow, startCol });
	visited[startRow][startCol] = true;

	const int maxRow = graph.size();
	const int maxCol = graph[0].size();

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	homeCount++;
	while (!q.empty())
	{
		int sRow = q.front().first;
		int sCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextRow = sRow + dx[i];
			int nextCol = sCol + dy[i];

			if (0 <= nextRow && nextRow < maxRow
				&& 0 <= nextCol && nextCol < maxCol
				&& visited[nextRow][nextCol] == false
				&& graph[nextRow][nextCol] == 1)
			{
				visited[nextRow][nextCol] = true;
				homeCount++;
				q.push({ nextRow, nextCol });
			}
		}
	}

	return homeCount;
}

int main()
{
	int graphSize;
	cin >> graphSize;

	// Initialize
	vector<string> strGraph(graphSize, "");
	for (int i = 0; i < graphSize; ++i)
	{
		cin >> strGraph[i];
	}

	vector< vector<int>> graph = StringGrpahToInt(strGraph, graphSize);
	vector< vector<bool>> visited(graphSize, vector<bool>(graphSize, false));

	// Calculate
	vector<int> homeGrid;
	for (int i = 0; i < graphSize; ++i)
	{
		for (int j = 0; j < graphSize; ++j)
		{
			if (graph[i][j] == 1 && visited[i][j] == false)
			{
				int count = BFS(graph, visited, i, j);
				homeGrid.push_back(count);
			}
		}
	}

	// Result
	int homeGridSize = homeGrid.size();
	cout << homeGridSize << '\n';

	// 단지수 적은순으로 오름차순
	sort(homeGrid.begin(), homeGrid.end());
	for (int i = 0; i < homeGridSize; ++i)
	{
		cout << homeGrid[i] << '\n';
	}


	return 0;
}