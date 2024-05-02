#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAX_VALUE (INT_MAX - 1)

vector<int> Dijkstra(vector< vector<int>>& graph, int start)
{
	int maxCount = graph.size();
	vector<int> distance(maxCount, MAX_VALUE);

	// first : cityID
	// second : cost
	priority_queue< pair<int, int>> pq;
	pq.push({ start, 0 });
	distance[start] = 0;

	while (!pq.empty())
	{
		int curCity = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();

		for (int i = 1; i < maxCount; ++i)
		{
			int nextCity = i;

			if (curCity == nextCity)
				continue;

			if (graph[curCity][nextCity] == MAX_VALUE)
				continue;

			int nextCost = distance[curCity] + graph[curCity][nextCity];
			if (distance[nextCity] > nextCost)
			{
				distance[nextCity] = nextCost;
				pq.push({ nextCity, nextCost });
			}
		}
	}


	return distance;
}

int main()
{
	int cityCount, busCount;
	cin >> cityCount >> busCount;

	vector< vector<int>> graph(cityCount + 1, vector<int>(cityCount + 1, MAX_VALUE));

	// Graph Init

	// 양방향 그래프가 아님.
	for (int i = 0; i < busCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		if (graph[start][end] > cost)
			graph[start][end] = cost;
	}

	// Target Input
	int targetStart, targetEnd;
	cin >> targetStart >> targetEnd;

	vector<int> distance = Dijkstra(graph, targetStart);
	cout << distance[targetEnd] << '\n';

	return 0;
}