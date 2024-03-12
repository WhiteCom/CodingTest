#include <iostream>
#include <vector>
#include <queue>

#define MAX_RANGE 101

using namespace std;

/*
뱀과 사다리 게임
1) 1번 시작, 100번 도착을 목표
2) 주사위 나온숫자 '+' 이동
3) 주사위 굴린 결과로 100번칸을 넘어서는 이동을 할 경우 이동불가
4) 사다리 : 해당좌표 '+' 이동, 뱀 : 해당좌표 '-' 이동
5) 게임판 상태가 주어질 때, 100번 도착하기 위해 굴려야할 주사위의 최소값?

=> 최단경로 찾는 문제임.
*/

struct graphData
{
	int movePos; // 이 좌표 왔을때 이동해야하는 다음좌표
	int moveTime; // 움직인 시간
};

void BFS(vector<graphData>& graph, vector<bool>& visited, int startPos, int targetPos)
{
	queue<int> q;
	q.push(startPos);
	visited[startPos] = true;

	const int diceCount = 6;
	int dice[6] = { 1, 2, 3, 4, 5, 6 };

	while (!q.empty())
	{
		int sPos = q.front();
		q.pop();

		if (graph[sPos].movePos > 0)
		{
			int beforeTime = graph[sPos].moveTime;

			sPos = graph[sPos].movePos;
			visited[sPos] = true;
			graph[sPos].moveTime = beforeTime;
		}

		if (sPos == targetPos)
		{
			cout << graph[sPos].moveTime << '\n';
		}

		// 6방향 존재 (주사위 6가지 경우)
		for (int i = 0; i < diceCount; ++i)
		{
			int nextPos = sPos + dice[i];
			if (0 <= nextPos && nextPos <= 100
				&& visited[nextPos] == false)
			{
				visited[nextPos] = true;
				graph[nextPos].moveTime = graph[sPos].moveTime + 1;

				q.push(nextPos);
			}
		}
	}
}

int main()
{
	int ladderCount, snakeCount;
	cin >> ladderCount >> snakeCount;

	vector<graphData> graph(MAX_RANGE, {0, 0});
	vector<bool> visited(MAX_RANGE, false);

	for (int i = 0; i < ladderCount; ++i)
	{
		int startPos, endPos;
		cin >> startPos >> endPos;
		graph[startPos].movePos = endPos;
	}

	for (int i = 0; i < snakeCount; ++i)
	{
		int startPos, endPos;
		cin >> startPos >> endPos;
		graph[startPos].movePos = endPos;
	}

	BFS(graph, visited, 1, 100);

	return 0;
}