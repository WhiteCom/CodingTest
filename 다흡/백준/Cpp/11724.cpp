#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct posData
{
	int y, x;
};

void DFS(vector< vector<bool>>& graph, vector<bool>& visited, int start)
{
	int maxVertex = graph.size();

	// �̹� �湮�� �����̸� ���
	if (visited[start] == true)
		return;

	visited[start] = true;

	for (int i = 0; i < maxVertex; ++i)
	{
		if (visited[i] == true)
			continue;

		if (graph[start][i] == true)
			DFS(graph, visited, i);
	}
}

void BFS(vector< vector<bool>>& graph, vector<bool>& visited, int start)
{
	int maxVertex = graph.size();

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int sPos = q.front();
		q.pop();

		for (int i = 0; i < maxVertex; ++i)
		{
			if (i == sPos)
				continue;

			if (visited[i] == true)
				continue;

			// ���� �������� �ٸ� �������� ���� ��� ����� push
			if (graph[sPos][i] == true)
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	int N, M; // N : node, M : edge
	cin >> N >> M;

	if (M == 0)
	{
		cout << N << '\n';
		return 0;
	}

	// graph : a -> b �� ���� ��ΰ� �����ϸ� true, �ƴϸ� false
	vector< vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
	vector<bool> visited(N + 1, false);

	// Initialize Graph
	for (int i = 0; i < M; ++i)
	{
		int start, end;
		cin >> start >> end;

		graph[start-1][end-1] = true;
		graph[end-1][start-1] = true;
	}
	
	// Calculate Graph
	int resultCount = 0;
 	for (int i = 0; i < N; ++i)
	{
		if (visited[i] == false)
		{
			//BFS(graph, visited, i);
			DFS(graph, visited, i);
			resultCount++;
		}
	}
	cout << resultCount << '\n';

	return 0;
}