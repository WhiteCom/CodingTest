#include <iostream>
#include <queue>
#include <vector>

#define MAX_RANGE 100001

using namespace std;

int BFS(vector<int>& graph, vector<bool>& visited, int startPos, int targetPos)
{
	// 시작과 목표점이 같은경우
	if (startPos == targetPos)
		return 0;

	queue<int> q; // pos
	q.push(startPos);
	
	graph[startPos] = 0;
	visited[startPos] = true;

	int left = 0;
	int right = 0;
	int move = 0;

	int smallestTime = 0;
	while (!q.empty())
	{
		int sPos = q.front();
		q.pop();
		
		if (sPos == targetPos)
		{
			smallestTime = graph[sPos];
			break;
		}
		
		// 좌, 우, 2배이동 좌표
		left = sPos - 1;
		right = sPos + 1;
		move = sPos * 2;

		// 좌, 우, 2배이동에 대해 시간체크 + 방문여부 체크
		// Left
		if (left >= 0 && left < MAX_RANGE
			&& visited[left] == false)
		{
			graph[left] = graph[sPos] + 1;

			visited[left] = true;
			q.push(left);
		}
		// Right
		if (right >= 0 && right < MAX_RANGE
			&& visited[right] == false)
		{
			graph[right] = graph[sPos] + 1;

			visited[right] = true;
			q.push(right);
		}

		// Move
		if (move >= 0 && move < MAX_RANGE
			&& visited[move] == false)
		{
			graph[move] = graph[sPos] + 1;

			visited[move] = true;
			q.push(move);
		}
	}

 	return smallestTime;
}

int main()
{
	int startPos, targetPos;
	cin >> startPos >> targetPos;

	vector<int> graph(100001, 0);
	vector<bool> visited(100001, false);

	int result = BFS(graph, visited, startPos, targetPos);

	cout << result << '\n';
	return 0;
}