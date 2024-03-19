#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector< vector<int>> Grid_StringToInt(vector<string>& grid)
{
	int gridSize = grid.size();
	vector< vector<int>> result(gridSize, vector<int>(gridSize, 0));

	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < grid[i].length(); ++j)
		{
			result[i][j] = grid[i][j] - '0';
		}
	}

	return result;
}

void Process_QuadTree(vector< vector<int>>& grid, int gridSize, int startRow, int startCol, string& result)
{
	int maxRow = grid.size();
	int maxCol = grid[0].size();

	// 범위 체크
	if (startRow < 0 || startRow >= maxRow || startCol < 0 || startCol >= maxCol)
		return;

	int oneCount = 0;
	int zeroCount = 0;
	for (int i = startRow; i < startRow + gridSize; ++i)
	{
		for (int j = startCol; j < startCol + gridSize; ++j)
		{
			if (grid[i][j] == 1)
				oneCount++;
			else if (grid[i][j] == 0)
				zeroCount++;
		}
	}

	// grid Area
	int targetCount = gridSize * gridSize;
	if (oneCount == targetCount)
	{
		result += '1';
		return;
	}
	else if (zeroCount == targetCount)
	{
		result += '0';
		return;
	}
	// 1, 0 어떤 경우도 현재 영역 사이즈보다 작은경우, 4방면 재귀탐색
	else
	{
		result += '(';

		// 1사분면
		Process_QuadTree(grid, gridSize / 2, startRow, startCol, result);
		// 2사분면
		Process_QuadTree(grid, gridSize / 2, startRow, startCol + gridSize / 2, result);
		// 3사분면
		Process_QuadTree(grid, gridSize / 2, startRow + gridSize / 2, startCol, result);
		// 4사분면
		Process_QuadTree(grid, gridSize / 2, startRow + gridSize / 2, startCol + gridSize / 2, result);

		result += ')';
	}
}

int main()
{
	int squareSize;
	cin >> squareSize;

	// Input
	vector<string> quadTree(squareSize, "");
	for (int i = 0; i < squareSize; ++i)
	{
		cin >> quadTree[i];
	}
	
	vector< vector<int>> grid = Grid_StringToInt(quadTree);

	string result = "";
	Process_QuadTree(grid, squareSize, 0, 0, result);

	cout << result << '\n';

	return 0;
}