#include <iostream>
#include <vector>

#define max(a, b) (a) < (b) ? (b) : (a)

using namespace std;

/*
테트로미노 경우의 수

5가지 테트로미노에 대해 회전, 대칭을 포함한 모든 경우의 수
=> 2 + 1 + 8 + 4 + 4 => 19가지

*/

//
// 1번 테트로미노
//
int FirstTetromino(vector< vector<int>>& graph)
{
	int maxCount = 0;

	int maxRow = graph.size();
	int maxCol = graph[0].size();

	// 1) 가로
	// 시작점으로부터 오른쪽으로 4칸 탐색
	for (int i = 0; i < maxRow; ++i)
	{
		for (int j = 3; j < maxCol; ++j)
		{
			int subSum = 0;
			// 가로 4칸 합
			subSum += graph[i][j] + graph[i][j-1] + graph[i][j-2] + graph[i][j-3];
			
			maxCount = max(maxCount, subSum);
		}
	}

	// 2) 세로
	// 시작점으로부터 아래쪽으로 4칸 탐색
	for (int j = 0; j < maxCol; ++j)
	{
		
		for (int i = 3; i < maxRow; ++i)
		{
			// 세로 4칸 합
			int subSum = 0;
			subSum += graph[i][j] + graph[i-1][j] + graph[i-2][j] + graph[i-3][j];

			maxCount = max(maxCount, subSum);
		}
	}

	return maxCount;
}

// 
// 2번 테트로미노
//
int SecondTetromino(vector< vector<int>>& graph)
{
	// 우측 1칸, 아래측 1칸 더 탐색필요

	int maxRow = graph.size();
	int maxCol = graph[0].size();

	int maxCount = 0;

	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			// 가로 2칸 합
			// 세로 2칸 합
			subSum += graph[i][j] + graph[i][j+1] + graph[i+1][j] + graph[i+1][j+1];
			
			maxCount = max(maxCount, subSum);
		}
	}

	return maxCount;
}

//
// 3번 테트로미노
//
int ThirdTetromino(vector< vector<int>>& graph)
{
	int maxRow = graph.size();
	int maxCol = graph[0].size();

	int maxCount = 0;

	// 1) 0
	//    0
	//    00
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 2][j + 1];

			maxCount = max(maxCount, subSum);
		}
	}
	
	// 2)  0
	//     0
	//    00
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 1; j < maxCol; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 2][j - 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 3) 000
	//    0
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i][j + 1] + graph[i][j + 2];

			maxCount = max(maxCount, subSum);
		}
	}

	// 4) 0
	//    000
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 1][j + 1] + graph[i + 1][j + 2];

			maxCount = max(maxCount, subSum);
		}
	}

	// 5) 00
	//     0
	//     0
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j + 1] + graph[i + 1][j + 1] + graph[i + 2][j + 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 6) 00
	//    0
	//    0
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j + 1] + graph[i + 1][j] + graph[i + 2][j];

			maxCount = max(maxCount, subSum);
		}
	}

	// 7)   0
	//    000
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 2; j < maxCol; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 1][j - 1] + graph[i + 1][j - 2];

			maxCount = max(maxCount, subSum);
		}
	}

	// 8) 000
	//      0
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum = graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i + 1][j + 2];

			maxCount = max(maxCount, subSum);
		}
	}

	return maxCount; 
}

//
// 4번 테트로미노
//
int FourthTetromino(vector< vector<int>>& graph)
{
	int maxRow = graph.size();
	int maxCol = graph[0].size();

	int maxCount = 0;

	// 1) 0
	//    00
	//     0
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 1][j + 1] + graph[i + 2][j + 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 2)  0
	//    00
	//    0
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 1; j < maxCol; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 1][j - 1] + graph[i + 2][j - 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 3) 00
	//   00
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 2; j < maxCol; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j - 1] + graph[i + 1][j - 1] + graph[i + 1][j - 2];

			maxCount = max(maxCount, subSum);
		}
	}

	// 4) 00
	//     00
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j + 1] + graph[i + 1][j + 1] + graph[i + 1][j + 2];

			maxCount = max(maxCount, subSum);
		}
	}

	return maxCount;
}

//
// 5번 테트로미노
//
int FifthTetromino(vector< vector<int>>& graph)
{
	int maxRow = graph.size();
	int maxCol = graph[0].size();

	int maxCount = 0;

	// 1) ㅜ
	for (int i = 0; i < maxRow - 1; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j + 1] + graph[i][j + 2] + graph[i + 1][j + 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 2) ㅗ
	for (int i = 1; i < maxRow; ++i)
	{
		for (int j = 0; j < maxCol - 2; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i][j + 1] + graph[i - 1][j + 1] + graph[i][j + 2];

			maxCount = max(maxCount, subSum);
		}
	}

	// 3) ㅏ
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 0; j < maxCol - 1; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 2][j] + graph[i + 1][j + 1];

			maxCount = max(maxCount, subSum);
		}
	}

	// 4) ㅓ
	for (int i = 0; i < maxRow - 2; ++i)
	{
		for (int j = 1; j < maxCol; ++j)
		{
			int subSum = 0;
			subSum += graph[i][j] + graph[i + 1][j] + graph[i + 1][j - 1] + graph[i + 2][j];

			maxCount = max(maxCount, subSum);
		}
	}

	return maxCount;
}

int main()
{
	int row, col;
	cin >> row >> col;

	vector< vector<int>> graph(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> graph[i][j];
		}
	}
	
	int maxResult = 0;

	// 1. 가로 1줄 테트로미노
	int firstResult = 0;
	firstResult = FirstTetromino(graph);

	// 2. 정사각형 테트로미노
	int secondResult = 0;
	secondResult = SecondTetromino(graph);

	// 3. 니은 모양 테트로미노
	int thirdResult = 0;
	thirdResult = ThirdTetromino(graph);

	// 4. 지그재그 테트로미노
	int fourthResult = 0;
	fourthResult = FourthTetromino(graph);

	// 5. 빠큐 테트로미노 
	int fifthResult = 0;
	fifthResult = FifthTetromino(graph);

	maxResult = max(maxResult, max(firstResult, max(secondResult, max(thirdResult, max(fourthResult, fifthResult)))));
	cout << maxResult << '\n';

	return 0;
}