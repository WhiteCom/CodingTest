#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector< vector<int>>& graph, vector< vector<bool>>& visit, int vertex, int startNum)
{
	if (visit[startNum][startNum] == true)
		return;

	visit[startNum][startNum] = true;
	cout << startNum << " ";

	for (int i = 0; i <= vertex; ++i)
	{
		if (visit[startNum][i] == false && visit[i][startNum] == false
			&& graph[startNum][i] == 1 && graph[i][startNum] == 1)
		{
			visit[startNum][i] = true;
			visit[i][startNum] = true;
			DFS(graph, visit, vertex, i);
		}
	}
}

void BFS(vector< vector<int>>& graph, vector< vector<bool>>& visit, int vertex, int startNum)
{
	queue<int> q;

	q.push(startNum);

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		if (visit[num][num] == false)
		{
			visit[num][num] = true;

			cout << num << " ";

			for (int i = 0; i <= vertex; ++i)
			{
				if (num == i)
					continue;

				if (visit[num][i] == true || visit[i][num] == true)
					continue;

				if (visit[num][i] == false && visit[i][num] == false
					&& graph[num][i] == 1 && graph[i][num] == 1)
				{
					q.push(i);
					visit[num][i] = true;
					visit[i][num] = true;
				}
			}
		}
	}
}

int main()
{
	int vertex, edge, startNum;
	cin >> vertex >> edge >> startNum;

	// Initialize
	vector< vector<int>> graph(vertex + 1, vector<int>(vertex + 1, 0));

	vector< vector<bool>> visit_BFS(vertex + 1, vector<bool>(vertex + 1, false));
	vector< vector<bool>> visit_DFS(vertex + 1, vector<bool>(vertex + 1, false));

	for (int i = 0; i < edge; ++i)
	{
		int startV, endV;
		cin >> startV >> endV;
		graph[startV][endV] = 1;
		graph[endV][startV] = 1;
	}

	DFS(graph, visit_DFS, vertex, startNum);
	cout << '\n';
	BFS(graph, visit_BFS, vertex, startNum);

	return 0;
}