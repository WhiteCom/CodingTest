#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_VALUE 101
#define min(a, b) (a) < (b) ? (a) : (b)

using namespace std;

struct KevinUser
{
	int value;
	int index;
};

bool compare(KevinUser k1, KevinUser k2)
{
	return k1.value < k2.value;
}

vector<int> Dijkstra(vector< vector<int>>& graph, int start)
{
	int maxVertex = graph.size();

	vector<int> distance(maxVertex + 1, MAX_VALUE);
	distance[start] = 0;

	// first : cost
	// second : vertex
	priority_queue< pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curCost = -pq.top().first;
		int curVertex = pq.top().second;

		pq.pop();

		// 기존에 기록해둔 해당 지점까지의 경로가 최단거리인경우 패스
		if (distance[curVertex] < curCost)
			continue;

		for (int i = 1; i < maxVertex; ++i)
		{
			// 자기자신이 다음방문인경우, 연결된 정점이 아닌경우 패스
			if (i == curVertex || graph[curVertex][i] == MAX_VALUE)
				continue;
			
			int nextVertex = i;
			int nextCost = curCost + graph[curVertex][i];

			if (distance[nextVertex] > nextCost)
			{
				distance[nextVertex] = nextCost;
				pq.push({ -nextCost, nextVertex });
			}
				
		}
	}

	return distance;
}

int DistanceSum(vector<int>& distance)
{
	int sum = 0;

	for (int i = 1; i < distance.size(); ++i)
	{
		if (distance[i] == MAX_VALUE)
			continue;

		sum += distance[i];
	}

	return sum;
}

int main()
{
	int userCount, relationCount;
	cin >> userCount >> relationCount;

	vector< vector<int>> graph(userCount + 1, vector<int>(userCount + 1, MAX_VALUE));

	// Input
	for (int i = 0; i < relationCount; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}

	// Calculate
	int result = MAX_VALUE;

	// 유저별 케빈베이컨 수
	vector<KevinUser> kevinBacon;

	for (int i = 1; i <= userCount; ++i)
	{
		vector<int> distance = Dijkstra(graph, i);
		int sum = DistanceSum(distance);

		if (sum == 0)
			continue;

		kevinBacon.push_back({ sum, i });
	}

	sort(kevinBacon.begin(), kevinBacon.end(), compare);

	cout << kevinBacon[0].index << '\n';

	return 0;
}