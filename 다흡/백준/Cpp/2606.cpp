#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector< vector<int>>& graph, vector<bool>& visited, int start, int& resultCount)
{
	queue<int> q; // input start vertex
	q.push(start);
	visited[start] = true;
	
	while (!q.empty())
	{
		int _start = q.front();
		q.pop();

		int relationCount = graph[_start].size();
		for (int i = 0; i < relationCount; ++i)
		{
			int next = graph[_start][i];
			if (visited[next] == false)
			{
				visited[next] = true;
				q.push(next);
				resultCount++;
			}
		}
	}
}

void DFS(vector< vector<int>>& graph, vector<bool>& visited, int start, int& resultCount)
{
	if (visited[start] == true)
		return;

	visited[start] = true;
	
	int relationCount = graph[start].size();
	for (int i = 0; i < relationCount; ++i)
	{
		int next = graph[start][i];
		if (visited[next] == false)
		{
			resultCount++;
			DFS(graph, visited, next, resultCount);
		}
	}
}

int main()
{
	int graphNum;
	int relationNum;

	cin >> graphNum >> relationNum;

	vector< vector<int>> graph(graphNum + 1);
	vector<bool> visited(graphNum, false);

	for (int i = 0; i < relationNum; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	int resultCount = 0;
	//BFS(graph, visited, 1, resultCount);
	DFS(graph, visited, 1, resultCount);
	cout << resultCount << '\n';

	return 0;
}