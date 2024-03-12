#include <iostream>
#include <vector>
#include <queue>

#define MAX_RANGE 101

using namespace std;

/*
��� ��ٸ� ����
1) 1�� ����, 100�� ������ ��ǥ
2) �ֻ��� ���¼��� '+' �̵�
3) �ֻ��� ���� ����� 100��ĭ�� �Ѿ�� �̵��� �� ��� �̵��Ұ�
4) ��ٸ� : �ش���ǥ '+' �̵�, �� : �ش���ǥ '-' �̵�
5) ������ ���°� �־��� ��, 100�� �����ϱ� ���� �������� �ֻ����� �ּҰ�?

=> �ִܰ�� ã�� ������.
*/

struct graphData
{
	int movePos; // �� ��ǥ ������ �̵��ؾ��ϴ� ������ǥ
	int moveTime; // ������ �ð�
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

		// 6���� ���� (�ֻ��� 6���� ���)
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