#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector< vector<int>> StringGraphToInt(vector<string>& inpGraph, int row, int col)
{
	vector< vector<int>> graph(row, vector<int>(col, 0));

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			graph[i][j] = inpGraph[i][j] - '0';
		}
	}

	return graph;
}

void BFS(vector< vector<int>>& graph, vector< vector<bool>>& visited, int startRow, int startCol, int targetRow, int targetCol)
{
	queue< pair<int, int>> q;
	q.push({ startRow, startCol });
	visited[startRow][startCol] = true;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	while (!q.empty())
	{
		int sRow = q.front().first;
		int sCol = q.front().second;
		q.pop();

		if (sRow == targetRow && sCol == targetCol)
		{
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nextRow = sRow + dx[i];
			int nextCol = sCol + dy[i];

			if (0 <= nextRow && nextRow <= targetRow
				&& 0 <= nextCol && nextCol <= targetCol
				&& visited[nextRow][nextCol] == false
				&& graph[nextRow][nextCol] == 1)
			{
				visited[nextRow][nextCol] = true;
				graph[nextRow][nextCol] = graph[sRow][sCol] + 1;
				q.push({ nextRow, nextCol });
			}
		}
	}
}

int main()
{
	int row, col;
	cin >> row >> col;
	vector<string> inpGraph(row, "");
	vector< vector<bool>> visited(row, vector<bool>(col, false));

	for (int i = 0; i < row; ++i)
	{
		cin >> inpGraph[i];
	}

	vector< vector<int>> graph = StringGraphToInt(inpGraph, row, col);

	BFS(graph, visited, 0, 0, row - 1, col - 1);
	cout << graph[row - 1][col - 1] << '\n';

	return 0;
}