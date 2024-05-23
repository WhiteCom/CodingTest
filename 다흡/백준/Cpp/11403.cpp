#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 1000

using namespace std;

vector<int> BFS(vector< vector<int>>& graph, int start)
{
	int maxVertex = graph.size();
	
	// 그래프에서 start -> 임의점 갈 수 있는지 여부만 체크
	vector<int> result(maxVertex, 0);
	vector<int> visited(maxVertex, false);

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int curVertex = q.front();
		q.pop();

		for (int i = 0; i < maxVertex; ++i)
		{
			int nextVertex = i;
			if (curVertex == nextVertex)
				continue;

			if (graph[curVertex][nextVertex] == 1 
				&& visited[nextVertex] == false)
			{
				visited[nextVertex] = true;
				result[nextVertex] = 1;
				q.push(nextVertex);
			}
		}
	}

	return result;
}

int main()
{
	int vertexCount;
	cin >> vertexCount;

	vector< vector<int>> graph(vertexCount, vector<int>(vertexCount, 0));

	//
	// Input
	//
	for (int i = 0; i < vertexCount; ++i)
	{
		for (int j = 0; j < vertexCount; ++j)
		{
			cin >> graph[i][j];
		}
	}

	//
	// Calculate
	//
	vector< vector<int>> result;
	for (int i = 0; i < vertexCount; ++i)
	{
		vector<int> distance = BFS(graph, i);

		result.push_back(distance);
	}

	//
	// Print
	//
	for (int i = 0; i < vertexCount; ++i)
	{
		for (int j = 0; j < vertexCount; ++j)
			cout << result[i][j] << " ";
		cout << '\n';
	}

	return 0;
}