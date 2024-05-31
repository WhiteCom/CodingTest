#include <iostream>
#include <vector>
#include <queue>

#define MAX_VALUE 20000000

using namespace std;

vector <long long int> Dijkstra(vector< vector< pair<int, int>>>& graph, int start)
{
	int maxVertex = graph.size();
	vector<long long int> distance(maxVertex, MAX_VALUE);

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

	//
	// Input
	//
	int vertexCount, nodeCount;
	cin >> vertexCount >> nodeCount;

	// first : vertex
	// second : cost
	vector< vector< pair<int, int>>> graph(vertexCount + 1);
	
	for (int i = 0; i < nodeCount; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}

	//
	// Calculate
	//
	int mid_vertex1, mid_vertex2;
	cin >> mid_vertex1 >> mid_vertex2;
	int targetVertex = vertexCount;

	// Case 1 : start...mid_1...mid_2...target
	vector<long long int> case1_distance1 = Dijkstra(graph, 1);
	vector<long long int> case1_distance2 = Dijkstra(graph, mid_vertex1);
	vector<long long int> case1_distance3 = Dijkstra(graph, mid_vertex2);

	long long int distance_result1 = case1_distance1[mid_vertex1] + case1_distance2[mid_vertex2] + case1_distance3[targetVertex];


	// Case 2 : start...mid_2...mid_1...target
	vector<long long int> case2_distance1 = Dijkstra(graph, 1);
	vector<long long int> case2_distance2 = Dijkstra(graph, mid_vertex2);
	vector<long long int> case2_distance3 = Dijkstra(graph, mid_vertex1);

	long long int distance_result2 = case2_distance1[mid_vertex2] + case2_distance2[mid_vertex1] + case2_distance3[targetVertex];

	int result = distance_result1 < distance_result2 ? distance_result1 : distance_result2;
	if (result >= MAX_VALUE)
		result = -1;
	cout << result << '\n';

	return 0;
}