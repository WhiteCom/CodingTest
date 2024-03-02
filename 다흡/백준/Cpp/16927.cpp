#include <iostream>
#include <vector>

using namespace std;

//============================================================
// https://www.acmicpc.net/problem/16927
// 
// 구현문제
// 입력된 배열 N * M 사이즈 배열을 R번 반시계방향으로 회전시켰을 때, 
// 회전된 배열을 출력하라
// 
// 1. 각 영역마다 (가로길이 - 1) * 2 + (세로길이 - 1) * 2를하면 1바퀴를 돌게 된다. 
// 즉, 이 값으로 회전 횟수 r을 나눈 나머지가 유의미하게 회전할 횟수이다. 
// 2. 유의미한 회전 횟수를 구한 후, 회전 횟수 만큼 각 변을 회전시킨다. 
// 3. 하나의 영역이 완료되면, 내부 영역으로 옮기고 1번부터 다시 수행한다.
//============================================================

void solution(vector< vector<int>>& arr, int N, int M, int R)
{
	// 꼭지점 4개
	int y1 = 0;
	int x1 = 0;

	int y2 = N - 1;
	int x2 = 0;

	int y3 = N - 1;
	int x3 = M - 1;

	int y4 = 0;
	int x4 = M - 1;

	// 가장 바깥 영역부터 안으로 들어가기
	while ((y1 < y2) && (x1 < x4))
	{
		// 영역 내에서 의미있게 회전할 횟수 구하기
		int move = R % ((y2 - y1) * 2 + (x4 - x1) * 2);

		while (move--)
		{
			// Rotate
			int tmp = arr[y1][x1];

			// Up
			for (int j = x1; j < x4; j++)
			{
				arr[y1][j] = arr[y1][j + 1];
			}

			// Right
			for (int i = y4; i < y3; i++)
			{
				arr[i][x4] = arr[i + 1][x4];
			}

			// Down
			for (int j = x3; j > x2; j--)
			{
				arr[y3][j] = arr[y3][j - 1];
			}

			// Left
			for (int i = y2; i > y1; i--)
			{
				arr[i][x2] = arr[i - 1][x2];
			}

			arr[y1 + 1][x1] = tmp;
		}

		// 회전이 끝났으면, 영역 옮기기
		y1 += 1;
		x1 += 1;

		y2 -= 1;
		x2 += 1;

		y3 -= 1;
		x3 -= 1;

		y4 += 1;
		x4 -= 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N : Row
	// M : Col
	int N, M, R;
	cin >> N >> M >> R;

	// init
	vector< vector<int>> arr(N);
	for (int i = 0; i < N; ++i)
	{
		arr[i] = vector<int>(M);
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}

	solution(arr, N, M, R);

	// print
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}