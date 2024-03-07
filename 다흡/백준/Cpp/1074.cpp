#include <iostream>
#include <vector>

using namespace std;

int pow(int n)
{
	int result = 1;
	while (n > 0)
	{
		result *= 2;
		n--;
	}

	return result;
}
 
void Recursion(int curLen, int startRow, int startCol, int targetRow, int targetCol, int& resultCount)
{
	if (startRow == targetRow && startCol == targetCol)
	{
		cout << resultCount << '\n';
		return;
	}

	if(startRow <= targetRow && targetRow < startRow + curLen 
		&& startCol <= targetCol && targetCol < targetCol + curLen)
	{
		int nextLen = curLen / 2;

		if (nextLen > 0)
		{
			// 1사분면
			Recursion(nextLen, startRow, startCol, targetRow, targetCol, resultCount);
			// 2사분면
			Recursion(nextLen, startRow, startCol + nextLen, targetRow, targetCol, resultCount);
			// 3사분면
			Recursion(nextLen, startRow + nextLen, startCol, targetRow, targetCol, resultCount);
			// 4사분면
			Recursion(nextLen, startRow + nextLen, startCol + nextLen, targetRow, targetCol, resultCount);
		}
		else
		{
			resultCount++;
		}
	}
	else
	{
		resultCount += curLen * curLen;
	}
}

int main()
{
	int N, targetRow, targetCol;
	cin >> N >> targetRow >> targetCol;

	int visitCount = 0;
	int gridRow = pow(N);
	int gridCol = pow(N);
	int resultCount = 0;

	Recursion(gridRow, 0, 0, targetRow, targetCol, resultCount);

	return 0;
}