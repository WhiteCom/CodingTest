#include <iostream>
#include <vector>

#define MAX_VALUE 50000
#define min(num1, num2) (num1) < (num2) ? (num1) : (num2)

using namespace std;

void Reset(vector<int>& distance, vector<bool>& visited)
{
	for (int i = 0; i < distance.size(); ++i)
		distance[i] = MAX_VALUE;

	for (int i = 0; i < visited.size(); ++i)
		visited[i] = false;
}

void Dijkstra(vector< vector<int>>& graph, vector<int>& distance, vector<bool>& visited, int graphSize, int start)
{
	// 거리 초기화
	for (int i = 0; i < graphSize; ++i)
	{
		distance[i] = graph[start][i];
	}

	visited[start] = true;
	// 가장 가까운 정점 방문
	while (true)
	{
		int minDistance = MAX_VALUE;
		int nextPos = -1;

		// 현재 노드로부터 가장 가까운 다음 정점 탐색
		for (int i = 0; i < graphSize; ++i)
		{
			if (minDistance > distance[i] && visited[i] == false)
			{
				minDistance = distance[i];
				nextPos = i;
			}
		}

		// 더이상 방문할 정점이 없는경우
		if (nextPos == -1 || distance[nextPos] == MAX_VALUE || visited[nextPos] == true)
			break;

		// 최단경로 갱신
		visited[nextPos] = true;
		for (int i = 0; i < graphSize; ++i)
		{
			if (visited[i] == true || graph[nextPos][i] > 1)
				continue;

			distance[i] = min(distance[i], distance[nextPos] + graph[nextPos][i]);
		}
	}
}

int DistanceSum(vector<int>& distance)
{
	int sum = 0;
	for (int i = 0; i < distance.size(); ++i)
	{
		if (distance[i] == MAX_VALUE)
			continue;

		sum += distance[i];
	}

	return sum;
}

int FindSmallestIndex(vector<int>& distanceSum)
{
	int minValue = MAX_VALUE;
	int minIndex = 0;
	for (int i = 0; i < distanceSum.size(); ++i)
	{
		if (minValue > distanceSum[i])
		{
			minValue = distanceSum[i];
			minIndex = i + 1;
		}
	}

	return minIndex;
}

int main()
{
	int userCount, relationCount;
	cin >> userCount >> relationCount;
	vector< vector<int>> graph(userCount, vector<int>(userCount, MAX_VALUE));
	for (int i = 0; i < relationCount; ++i)
	{
		int startUser, endUser;
		cin >> startUser >> endUser;
		graph[startUser - 1][endUser - 1] = 1;
		graph[endUser - 1][startUser - 1] = 1;
	}

	vector<int> distance(userCount, MAX_VALUE);
	vector<bool> visited(userCount, false);

	vector<int> distanceSum(userCount, 0);

	for (int i = 0; i < userCount; ++i)
	{
		Dijkstra(graph, distance, visited, userCount, i);

		// 거리 합 계산
		distanceSum[i] = DistanceSum(distance);

		Reset(distance, visited);
	}

	cout << FindSmallestIndex(distanceSum) << '\n';

	return 0;
}