#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
PCCP 2번 석유시추 문제
- BFS 이용해서 석유가 있는 지역들의 연결성 확인.
- 석유가 있는 땅인경우, 마지막 방문지점까지 거리를 계산하여, 연결된 땅의 석유시추량을 갱신.
- 위와같이 할 경우 한 땅만 파내도 얼마만큼의 석유를 퍼낼 수 있는지를 계산가능.
*/

struct landData
{
	int landNum; // 석유가 있는곳인경우, id 값
	bool visited; // 방문여부
	int oilValue; // 현재 석유존재여부
	int totalOil; // 해당 땅을 파낸경우 총 획득가능한 석유량
};

struct posData
{
	int y, x;
};

// 현재 석유가 매장된 곳을 파낸경우, 얻을 수 있는 총량
int BFS(vector< vector<landData>>& land, vector<bool>& oilLandCheck, int startY, int startX)
{
	int totalOil = 0; // 현재 시작점으로부터 얻을 수 있는 총 석유량

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

			// 범위 체크
			if (nextPos.x < 0 || nextPos.x >= maxCol)
				continue;

			if (nextPos.y < 0 || nextPos.y >= maxRow)
				continue;

			// 방문여부 체크
			if (land[nextPos.y][nextPos.x].visited == true)
				continue;

			// 석유가 매장된 곳인지 체크
			if (land[nextPos.y][nextPos.x].oilValue == 1)
			{
				land[nextPos.y][nextPos.x].visited = true;
				// check 배열은 열 값 사용중이므로 x인덱스 이용
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

	// 새로운 오일 그래프 생성 ( 오일이 있는 땅 번호, 방문여부, 현재 석유 존재여부, 해당 부위 진입시 얻을 수 있는 총 석유량 )
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

	vector<bool> oilLandCheck(col, false); // 석유뭉치 BFS 탐색후 석유총량 계산시, 해당 열(col) 에 대해 중복탐색 방지용.
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

				// 현재 채굴한 석유총량이 어느 열에 속해있는지 체크후, 미리 합산값 저장.
				// 이후 다음 열 탐색을 위해 check 초기화.
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
