#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 10001

using namespace std;

vector<int> Dijkstra(vector< vector< pair<int, int>>>& graph, int start)
{
	int maxVertex = graph.size();
	vector<int> distance(maxVertex + 1, MAX_VALUE);

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

	// Input
	int userCount, nodeCount;
	cin >> userCount >> nodeCount;

	vector< vector< pair<int, int>>> graph(userCount + 1);
	for (int i = 0; i < nodeCount; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start].push_back({ end, 1 });
		graph[end].push_back({ start, 1 });
	}

	// first : userIndex
	// second : sum
	pair<int, int> kevinValue = { MAX_VALUE, MAX_VALUE };
	for (int i = 1; i <= userCount; ++i)
	{
		vector<int> distance = Dijkstra(graph, i);

		int tempSum = 0;
		for (int j = 1; j < distance.size() - 1; ++j)
		{
			tempSum += distance[j];
		}
		
		pair<int, int> tempKevinValue = { i, tempSum };
		if (kevinValue.second >= tempKevinValue.second)
		{
			if (kevinValue.second == tempKevinValue.second)
				kevinValue.first = kevinValue.first > tempKevinValue.first ? tempKevinValue.first : kevinValue.first;
			else
				kevinValue.first = tempKevinValue.first;

			kevinValue.second = tempKevinValue.second;
		}
	}

	cout << kevinValue.first;

	return 0;
}