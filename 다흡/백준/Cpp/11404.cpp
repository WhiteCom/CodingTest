#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX_VALUE INT_MAX // 비용이 한 간선당 최대 100,000 이므로 가능하면 max 수치는 크게하기.

using namespace std;

vector<int> Dijkstra(vector< vector<int>>& graph, int start)
{
	int maxCount = graph.size(); 
	vector<int> distance(maxCount, MAX_VALUE);

	// first : cityId
	// second : cost
	priority_queue< pair<int, int>> pq;
	pq.push({ start, 0 });
	distance[start] = 0;

	while (!pq.empty())
	{
		int curCity = pq.top().first;
		int curCost = -pq.top().second;
		pq.pop();

		for (int i = 1; i < maxCount; ++i)
		{
			if (curCity == i)
				continue;

			if (graph[curCity][i] == MAX_VALUE)
				continue;

			int nextCity = i;
			if (distance[nextCity] > distance[curCity] + graph[curCity][nextCity])
			{
				int nextCost = distance[curCity] + graph[curCity][nextCity];
				distance[nextCity] = nextCost;
				pq.push({ nextCity, -nextCost });
			}
		}
	}

	return distance;
}

int main()
{
	int cityCount;
	cin >> cityCount;

	int busCount;
	cin >> busCount;

	vector< vector<int>> graph(cityCount + 1, vector<int>(cityCount + 1, MAX_VALUE));

	// Input
	for (int i = 0; i < busCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		// 방향그래프임.
		if (graph[start][end] > cost)
		{
			graph[start][end] = cost;
		}
	}

	//
	// i 번째 줄에서 j 번째 열까지 가는데 걸리는 최소비용 출력하기 (cityCount * cityCount 사이즈)
	//
	vector< vector<int>> resultDistance(cityCount + 1, vector<int>(cityCount + 1, MAX_VALUE));

	for (int i = 1; i <= cityCount; ++i)
	{
		resultDistance[i] = Dijkstra(graph, i);
	}

	// Print
	for (int i = 1; i <= cityCount; ++i)
	{
		for (int j = 1; j <= cityCount; ++j)
		{
			if (resultDistance[i][j] >= MAX_VALUE)
				cout << 0 << " ";
			else
				cout << resultDistance[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}