#include <iostream>
#include <vector>

using namespace std;

int maxNum = 0;
int maxVertex = 0;

void DFS(vector< vector< pair<int, int>>>& graph, vector<bool>& visited, int start, int& result)
{
	if (visited[start] == true)
		return;

	visited[start] = true;

	if (maxNum < result)
	{
		maxNum = result;
		maxVertex = start;
	}

	for (int i = 0; i < graph[start].size(); ++i)
	{
		int nextVertex = graph[start][i].first;
		int nextCost = graph[start][i].second;
		if (visited[nextVertex] == true)
			continue;

		result += nextCost;
		DFS(graph, visited, nextVertex, result);
		result -= nextCost;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int vertexCount;
	cin >> vertexCount;

	// first : vertex
	// second : cost
	vector< vector< pair<int, int>>> graph(vertexCount + 1);

	for (int i = 0; i < vertexCount; ++i)
	{
		int start;
		cin >> start;

		while (true)
		{
			int end, cost;
			cin >> end;
			if (end == -1)
				break;

			cin >> cost;
			graph[start].push_back({ end, cost });
		}
	}

	// 모든 정점에 대해 DFS 수행시 시간초과 발생
	/*
	for (int i = 1; i <= vertexCount; ++i)
	{
		vector<bool> visited(vertexCount + 1, false);
		int distance = 0;
		DFS(graph, visited, i, distance);
	}
	*/

	// 목표는 트리의 지름을 구하는 것이므로,
	// DFS는 단 2번 시행하면 된다.
	// 1 : 임의 정점에서 마지막 정점까지의 거리중 최대거리 및 마지막에 구한 정점 찾기
	// 2 : 1에서 구한 마지막 정점에서 다시 탐색을 시작하여 최대거리 찾기
	vector<bool> visited(vertexCount + 1, false);
	int distance = 0;
	DFS(graph, visited, 1, distance);

	for (int i = 0; i < vertexCount + 1; ++i)
		visited[i] = false;

	distance = 0;
	DFS(graph, visited, maxVertex, distance);

	cout << maxNum << '\n';

	return 0;
}