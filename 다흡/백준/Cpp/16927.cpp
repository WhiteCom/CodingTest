#include <iostream>
#include <vector>

using namespace std;

//============================================================
// https://www.acmicpc.net/problem/16927
// 
// ��������
// �Էµ� �迭 N * M ������ �迭�� R�� �ݽð�������� ȸ�������� ��, 
// ȸ���� �迭�� ����϶�
// 
// 1. �� �������� (���α��� - 1) * 2 + (���α��� - 1) * 2���ϸ� 1������ ���� �ȴ�. 
// ��, �� ������ ȸ�� Ƚ�� r�� ���� �������� ���ǹ��ϰ� ȸ���� Ƚ���̴�. 
// 2. ���ǹ��� ȸ�� Ƚ���� ���� ��, ȸ�� Ƚ�� ��ŭ �� ���� ȸ����Ų��. 
// 3. �ϳ��� ������ �Ϸ�Ǹ�, ���� �������� �ű�� 1������ �ٽ� �����Ѵ�.
//============================================================

void solution(vector< vector<int>>& arr, int N, int M, int R)
{
	// ������ 4��
	int y1 = 0;
	int x1 = 0;

	int y2 = N - 1;
	int x2 = 0;

	int y3 = N - 1;
	int x3 = M - 1;

	int y4 = 0;
	int x4 = M - 1;

	// ���� �ٱ� �������� ������ ����
	while ((y1 < y2) && (x1 < x4))
	{
		// ���� ������ �ǹ��ְ� ȸ���� Ƚ�� ���ϱ�
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

		// ȸ���� ��������, ���� �ű��
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