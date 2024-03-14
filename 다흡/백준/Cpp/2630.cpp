#include <iostream>
#include <vector>

using namespace std;

// ��� ���������� üũ�� �Ͼ�, �Ķ� ������
// Whilte : 0
// Blue : 1

void ResetVisited(vector< vector<bool>>& visited, int row, int col, int length)
{
	for (int i = row; i < row + length; ++i)
	{
		for (int j = col; j < col + length; ++j)
		{
			visited[i][j] = false;
		}
	}
}

int WhiteBoxCount(vector< vector<int>>& graph, vector< vector<bool>>& visited, int row, int col, int length)
{
	int whiteCount = 0;
	for (int i = row; i < row + length; ++i)
	{
		for (int j = col; j < col + length; ++j)
		{
			if (graph[i][j] == 0 && visited[i][j] == false)
			{
				visited[i][j] = true;
				whiteCount++;
			}
			else if (graph[i][j] == 0 && visited[i][j] == true)
				return 0;
		}
	}

	// �ش� ������ black �������ΰ��
	int gridSize = length * length;
	if (whiteCount == gridSize)
		return 1;

	ResetVisited(visited, row, col, length);

	return 0;
}

int BlueBoxCount(vector< vector<int>>& graph, vector< vector<bool>>& visited, int row, int col, int length)
{
	int blueCount = 0;
	for (int i = row; i < row + length; ++i)
	{
		for (int j = col; j < col + length; ++j)
		{
			if (graph[i][j] == 1 && visited[i][j] == false)
			{
				visited[i][j] = true;
				blueCount++;
			}
			else if (graph[i][j] == 1 && visited[i][j] == true)
				return 0;
		}
	}

	// �ش� ������ black �������ΰ��
	int gridSize = length * length;
	if (blueCount == gridSize)
		return 1;

	ResetVisited(visited, row, col, length);

	return 0;
}

void Recursion(vector< vector<int>>& graph, vector< vector<bool>>& blueVisited, vector< vector<bool>>& whiteVisited, int row, int col, int length, int& whiteCount, int& blueCount)
{
	int curWhiteCount = WhiteBoxCount(graph, whiteVisited, row, col, length);
	int curBlueCount = BlueBoxCount(graph, blueVisited, row, col, length);
	whiteCount += curWhiteCount;
	blueCount += curBlueCount;

	// ��� ��������
	if (length > 1)
	{
		int halfLength = length / 2;
		int _row, _col;
		// 1��и�
		_row = row, _col = col;
		Recursion(graph, blueVisited, whiteVisited, _row, _col, length / 2, whiteCount, blueCount);

		// 2��и�
		_row = row, _col = col + halfLength;
		Recursion(graph, blueVisited, whiteVisited, _row, _col, length / 2, whiteCount, blueCount);

		// 3��и�
		_row = row + halfLength, _col = col;
		Recursion(graph, blueVisited, whiteVisited, _row, _col, length / 2, whiteCount, blueCount);

		// 4��и�
		_row = row + halfLength, _col = col + halfLength;
		Recursion(graph, blueVisited, whiteVisited, _row, _col, length / 2, whiteCount, blueCount);
	}
}

int main()
{
	int num;
	cin >> num;

	vector< vector<int>> graph(num, vector<int>(num, 0));
	vector< vector<bool>> blueVisited(num, vector<bool>(num, false));
	vector< vector<bool>> whiteVisited(num, vector<bool>(num, false));

	// Initialization
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> graph[i][j];
		}
	}

	int whiteCount = 0;
	int blueCount = 0;

	Recursion(graph, blueVisited, whiteVisited, 0, 0, num, whiteCount, blueCount);

	cout << whiteCount << '\n' << blueCount << '\n';

	return 0;
}