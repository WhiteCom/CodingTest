#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX_VALUE (INT_MAX - 1)

using namespace std;

vector<int> Dijkstra(vector< vector< pair<int, int>>>& graph, int start, int target)
{
	int maxVertex = graph.size();
	vector<int> distance(maxVertex, MAX_VALUE);

	vector<bool> visited(maxVertex, false);

	// first : cost
	// second : vertex
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
	pq.push({ 0, start });
	visited[start] = true;

	while (!pq.empty())
	{
		int curCost = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		if (curCost > distance[curVertex])
			continue;

		for (int i = 0; i < graph[curVertex].size(); ++i)
		{
			int nextVertex = graph[curVertex][i].first;
			int nextCost = graph[curVertex][i].second;

			int nextMoveCost = curCost + nextCost;
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

	int personCount, nodeCount, target;
	cin >> personCount >> nodeCount >> target;

	// 단방향 그래프
	// first : end vertex
	// second : cost
	vector< vector< pair<int, int>>> graph(personCount + 1);

	for (int i = 0; i < nodeCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
	}

	int maxValue = 0;
	for (int i = 1; i <= personCount; ++i)
	{
		if (i == target)
			continue;

		// 타겟까지 가는데 최소경로
		vector<int> distance_GoTarget = Dijkstra(graph, i, target);
		int goValue = distance_GoTarget[target];

		// 타겟에서 돌아오는데 최소경로
		vector<int> distance_BackTarget = Dijkstra(graph, target, i);
		int backValue = distance_BackTarget[i];

		int tempSum = goValue + backValue;
		maxValue = maxValue < tempSum ? tempSum : maxValue;
	}

	cout << maxValue << '\n';

	return 0;
}