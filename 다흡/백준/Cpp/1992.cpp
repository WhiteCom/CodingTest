#include <iostream>
#include <vector>

using namespace std;

void QuadTree(vector<vector<char>>& arr, int sX, int eX, int sY, int eY)
{
	int zeroNum = 0;
	int oneNum = 0;

	// 현재 분면의 한 축의 길이 ( X or Y )
	int nX = (eX - sX);
	int nY = (eY - sY);

	for (int i = sY; i < eY; ++i)
	{
		for (int j = sX; j < eX; ++j)
		{
			if (arr[i][j] - '0' == 0) zeroNum++;
			else if (arr[i][j] - '0' == 1) oneNum++;
		}
	}

	if (zeroNum == nX * nY)
	{
		cout << "0";
		return;
	}
	if (oneNum == nX * nY)
	{
		cout << "1";
		return;
	}

	// 0, 1 아닌경우 4분면으로 나눠서 다시 탐색
	// 1사분면
	
	int midX = (sX + eX) / 2;
	int midY = (sY + eY) / 2;

	cout << "(";

	QuadTree(arr,	sX,			midX,			sY,			midY);		// 1사분면
	QuadTree(arr,	midX,		eX,				sY,			midY);		// 2사분면
	QuadTree(arr,	sX,			midX,			midY,		eY);		// 3사분면
	QuadTree(arr,	midX,		eX,				midY,		eY);		// 4사분면

	cout << ")";
}

int main()
{
	int N;
	cin >> N;
	
	int zeroNum = 0;
	int oneNum = 0;

	vector<vector<char>> arr(N);
	for (int i = 0; i < N; ++i)
	{
		arr[i] = vector<char>(N, '-1');
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	QuadTree(arr, 0, N, 0, N);

	return 0;
}