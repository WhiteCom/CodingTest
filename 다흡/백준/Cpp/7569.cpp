#include <iostream>
#include <vector>
#include <queue>

#define MAX_TIME 1000000
#define min(num1, num2) (num1) < (num2) ? (num1) : (num2)
#define max(num1, num2) (num1) > (num2) ? (num1) : (num2)

using namespace std;

struct sData
{
	int value;
	int time;
	bool visited;
};

struct posData
{
	int z, y, x;
};

// 반례, 아래와 같은 경우를 생각해야하기에, 기존에 풀던 BFS 방식이 아닌 다른방식 필요
	/*
	5 3 1
	0 0 0 0 0
	1 0 0 0 1
	0 0 0 0 0
	answer : 3
	output : 5
	*/

void BFS(vector< vector< vector<sData>>>& graph, queue<posData>& q)
{
	int maxZ = graph.size();
	int maxY = graph[0].size();
	int maxX = graph[0][0].size();

	int dx[6] = { -1, 1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, -1, 1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, -1, 1 };

	while (!q.empty())
	{
		posData sPos;
		sPos.z = q.front().z;
		sPos.y = q.front().y;
		sPos.x = q.front().x;

		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			posData nextPos;
			nextPos.z = sPos.z + dz[i];
			nextPos.y = sPos.y + dy[i];
			nextPos.x = sPos.x + dx[i];

			if (0 <= nextPos.x && nextPos.x < maxX
				&& 0 <= nextPos.y && nextPos.y < maxY
				&& 0 <= nextPos.z && nextPos.z < maxZ
				&& graph[nextPos.z][nextPos.y][nextPos.x].value == 0)
			{
				graph[nextPos.z][nextPos.y][nextPos.x].value = 1;
				graph[nextPos.z][nextPos.y][nextPos.x].time = min(graph[nextPos.z][nextPos.y][nextPos.x].time, graph[sPos.z][sPos.y][sPos.x].time + 1);
				q.push(nextPos);
			}
		}
	}
}

int Result(vector< vector< vector<sData>>>& graph)
{
	int maxZ = graph.size();
	int maxY = graph[0].size();
	int maxX = graph[0][0].size();

	int maxTime = 0;
	for (int z = 0; z < maxZ; ++z)
	{
		for (int y = 0; y < maxY; ++y)
		{
			for (int x = 0; x < maxX; ++x)
			{
				// 벽 인경우 넘어가기
				if (graph[z][y][x].value == -1)
					continue;

				maxTime = max(maxTime, graph[z][y][x].time);
				
				// 결과값을 체크 중, 안익은 토마토가 있는경우
				if (graph[z][y][x].value == 0)
					return -1;
			} 
		}
	}

	return maxTime;
}

int main()
{
	int row, col, height;
	cin >> col >> row >> height;

	vector< vector< vector<sData>>> graph(height, vector< vector<sData>>(row, vector<sData>(col, { 0, MAX_TIME, false })));
	queue<posData> q; 

	// Init
	int zeroCount = 0;
	
	for (int z = 0; z < height; ++z)
	{
		for (int y = 0; y < row; ++y)
		{
			for (int x = 0; x < col; ++x)
			{
				cin >> graph[z][y][x].value;

				if (graph[z][y][x].value == 0)
					zeroCount++;
				else if (graph[z][y][x].value == 1)
				{
					// 초기에 익은 토마토가 있는경우 익은시간세팅.
					// 초기에 익은 토마토들이 있는 좌표 데이터 삽입
					graph[z][y][x].time = 0; 
					q.push({ z,y,x }); 
				}
			}
		}
	}

	// Calculate
	for (int z = 0; z < height; ++z)
	{
		for (int y = 0; y < row; ++y)
		{
			for (int x = 0; x < col; ++x)
			{
				if (graph[z][y][x].value == 1)
				{
					BFS(graph, q);
				}
			}
		}
	}

	
	cout << Result(graph) << '\n';

	return 0;
}