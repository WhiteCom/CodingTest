#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 200000

using namespace std;

vector<int> Dijkstra(vector< vector< pair<int, int>>>& graph, int vertexCount, int start)
{
	vector<int> distance(vertexCount + 1, MAX_VALUE);
	distance[start] = 0;

	priority_queue< pair<int, int>> pq;
	// first : cost
	// second : vertex
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curCost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		if (distance[curVertex] < curCost)
			continue;

		for (int i = 0; i < graph[curVertex].size(); ++i)
		{
			int nextCost = graph[curVertex][i].second;
			int nextVertex = graph[curVertex][i].first;

			int nextMoveCost = distance[curVertex] + nextCost;
			if (distance[nextVertex] > nextMoveCost)
			{
				distance[nextVertex] = nextMoveCost;
				pq.push({ -nextMoveCost, nextVertex });
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

	int vertexCount, nodeCount, start;
	cin >> vertexCount >> nodeCount >> start;

	vector< vector< pair<int, int>>> graph(vertexCount + 1);

	for (int i = 0; i < nodeCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
	}

	vector<int> distance = Dijkstra(graph, vertexCount, start);

	for (int i = 1; i < distance.size(); ++i)
	{
		if (distance[i] == MAX_VALUE)
			cout << "INF\n";

		else
			cout << distance[i] << '\n';
	}

	return 0;
}