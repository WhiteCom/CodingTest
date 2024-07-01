#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int BFS(vector< vector<char>>& graph, vector< vector<bool>>& visited, int startRow, int startCol, char color)
{
	int maxRow = graph.size();
	int maxCol = graph[0].size();

	// first : row
	// second : col;
	queue< pair<int, int>> q;
	q.push({ startRow, startCol });
	visited[startRow][startCol] = true;
	int curValue = 0;
	int curCount = 1;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	while (!q.empty())
	{
		int sRow = q.front().first;
		int sCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextRow = sRow + dy[i];
			int nextCol = sCol + dx[i];

			// 범위 체크
			if (nextRow < 0 || nextRow >= maxRow)
				continue;
			if (nextCol < 0 || nextCol >= maxCol)
				continue;
			
			// visited 체크
			if (visited[nextRow][nextCol] == true)
				continue;

			// 색깔 체크
			if (graph[nextRow][nextCol] == color)
			{
				curCount++;
				visited[nextRow][nextCol] = true;
				q.push({ nextRow, nextCol });
			}
		}
	}

	curValue = curCount * curCount;

	return curValue;
}
int main()
{
	int row, col;
	cin >> col >> row;

	vector<string> inpData(row, "");
	for (int i = 0; i < row; ++i)
	{
		cin >> inpData[i];
	}

	vector< vector<char>> graph(row, vector<char>(col, ' '));
	vector< vector<bool>> visited(row, vector<bool>(col, false));
	
	// Convert inpData -> graph
	for (int i = 0; i < inpData.size(); ++i)
	{
		for (int j = 0; j < inpData[i].length(); ++j)
		{
			graph[i][j] = inpData[i][j];
		}
	}

	int blackValue = 0;
	int whiteValue = 0;

	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 0; j < graph[0].size(); ++j)
		{
			if (graph[i][j] == 'W' && visited[i][j] == false)
				whiteValue += BFS(graph, visited, i, j, 'W');

			else if (graph[i][j] == 'B' && visited[i][j] == false)
				blackValue += BFS(graph, visited, i, j, 'B');
		}
	}

	cout << whiteValue << " " << blackValue << '\n';

	return 0;
}