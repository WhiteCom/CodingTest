#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
PCCP 2�� �������� ����
- BFS �̿��ؼ� ������ �ִ� �������� ���Ἲ Ȯ��.
- ������ �ִ� ���ΰ��, ������ �湮�������� �Ÿ��� ����Ͽ�, ����� ���� �������߷��� ����.
- ���Ͱ��� �� ��� �� ���� �ĳ��� �󸶸�ŭ�� ������ �۳� �� �ִ����� ��갡��.
*/

struct landData
{
	int landNum; // ������ �ִ°��ΰ��, id ��
	bool visited; // �湮����
	int oilValue; // ���� �������翩��
	int totalOil; // �ش� ���� �ĳ���� �� ȹ�氡���� ������
};

struct posData
{
	int y, x;
};

// ���� ������ ����� ���� �ĳ����, ���� �� �ִ� �ѷ�
int BFS(vector< vector<landData>>& land, vector<bool>& oilLandCheck, int startY, int startX)
{
	int totalOil = 0; // ���� ���������κ��� ���� �� �ִ� �� ������

	queue<posData> q;
	q.push({ startY, startX });
	land[startY][startX].visited = true;
	totalOil++;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	int maxRow = land.size();
	int maxCol = land[0].size();

	while (!q.empty())
	{
		posData sPos = q.front();

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			posData nextPos;
			nextPos.y = sPos.y + dy[i];
			nextPos.x = sPos.x + dx[i];

			// ���� üũ
			if (nextPos.x < 0 || nextPos.x >= maxCol)
				continue;

			if (nextPos.y < 0 || nextPos.y >= maxRow)
				continue;

			// �湮���� üũ
			if (land[nextPos.y][nextPos.x].visited == true)
				continue;

			// ������ ����� ������ üũ
			if (land[nextPos.y][nextPos.x].oilValue == 1)
			{
				land[nextPos.y][nextPos.x].visited = true;
				// check �迭�� �� �� ������̹Ƿ� x�ε��� �̿�
				oilLandCheck[nextPos.x] = true;
				totalOil++;
				q.push(nextPos);
			}
		}
	}

	return totalOil;
}

int solution(vector< vector<int>> land)
{
	int row = land.size();
	int col = land[0].size();

	// ���ο� ���� �׷��� ���� ( ������ �ִ� �� ��ȣ, �湮����, ���� ���� ���翩��, �ش� ���� ���Խ� ���� �� �ִ� �� ������ )
	vector< vector<landData>> oilGraph(row, vector<landData>(col, { 0, false, 0, 0 }));

	// Initialize
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			oilGraph[i][j].oilValue = land[i][j];
		}
	}

	// Calculate

	vector<bool> oilLandCheck(col, false); // ������ġ BFS Ž���� �����ѷ� ����, �ش� ��(col) �� ���� �ߺ�Ž�� ������.
	vector<int> oilSumContainer(col, 0);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (oilGraph[i][j].oilValue == 1
				&& oilGraph[i][j].visited == false)
			{
				oilLandCheck[j] = true;

				int oilSum = BFS(oilGraph, oilLandCheck, i, j);

				// ���� ä���� �����ѷ��� ��� ���� �����ִ��� üũ��, �̸� �ջ갪 ����.
				// ���� ���� �� Ž���� ���� check �ʱ�ȭ.
				for (int k = 0; k < col; ++k)
				{
					if (oilLandCheck[k] == 1)
					{
						oilLandCheck[k] = 0;
						oilSumContainer[k] += oilSum;
					}
				}
			}
		}
	}
	
	int maxOil = 0;

	for (int i = 0; i < col; ++i)
	{
		maxOil = maxOil < oilSumContainer[i] ? oilSumContainer[i] : maxOil;
	}

	return maxOil;
}

int main()
{
	int row, col; 
	cin >> row >> col;

	vector< vector<int>> land(row, vector<int>(col, 0));
	

	// Initialize
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> land[i][j];
		}
	}

	int result = solution(land);
	cout << result << '\n';

	return 0;
}
