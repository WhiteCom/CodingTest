#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 1000000

using namespace std;

vector<int> Dijkstra(vector< vector< pair<int, int>>>& graph, int start)
{
	int maxVertex = graph.size();
	vector<int> distance(maxVertex, MAX_VALUE);

	// first : cost
	// second : vertex
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ 0, start });
	distance[start] = 0;

	while (!pq.empty())
	{
		int curCost = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curVertex].size(); ++i)
		{
			int nextVertex = graph[curVertex][i].first;
			int nextCost = graph[curVertex][i].second;

			int nextMoveCost = distance[curVertex] + nextCost;
			if (distance[nextVertex] > nextMoveCost)
			{
				distance[nextVertex] = nextMoveCost;
				pq.push({ nextMoveCost, nextVertex });
			}
		}
	}

	return distance;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int vertexCount, queryCount;
	cin >> vertexCount >> queryCount;

	// 트리, 양방향 연결
	// first : end
	// second : cost
	vector < vector< pair<int, int>>> graph(vertexCount + 1);

	for (int i = 0; i < vertexCount - 1; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}

	for (int i = 0; i < queryCount; ++i)
	{
		int start, end;
		cin >> start >> end;
		vector<int> distance = Dijkstra(graph, start);

		// 반드시 목표지점으로 갈 수 있는 경우들만 주어진다고 가정
		cout << distance[end] << '\n';
	}

	return 0;
}