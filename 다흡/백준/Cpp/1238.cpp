#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX_VALUE (INT_MAX - 1)

using namespace std;

// direction 파라미터 : 현재 정방향인지, 역방향인지 체크용
vector<int> Dijkstra(vector< vector< vector< pair<int, int>>>>& graph, int direction, int start)
{
	int maxVertex = graph[direction].size();
	vector<int> distance(maxVertex, MAX_VALUE);

	// first : cost
	// second : vertex
	priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curCost = pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[direction][curVertex].size(); ++i)
		{
			int nextCost = graph[direction][curVertex][i].first;
			int nextVertex = graph[direction][curVertex][i].second;

			int nextMoveCost = curCost + nextCost;
			if(distance[nextVertex] > nextMoveCost)
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

	// 0 : 정방향 그래프
	// 1 : 역방향 그래프
	// first : cost
	// second : vertex
	vector < vector< vector< pair<int, int>>>> graph(2, vector< vector< pair<int, int>>>(personCount + 1));

	for (int i = 0; i < nodeCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[0][start].push_back({ cost, end });
		graph[1][end].push_back({ cost, start });
	}

	vector<int> distance = Dijkstra(graph, 0, target);
	vector<int> reverse_distance = Dijkstra(graph, 1, target);

	int maxValue = 0;
	for (int i = 1; i <= personCount; ++i)
	{
		if (i == target)
			continue;

		int tempSum = distance[i] + reverse_distance[i];
		maxValue = maxValue > tempSum ? maxValue : tempSum;
	}

	cout << maxValue << '\n';

	return 0;
}