#include <iostream>
#include <vector>
#include <climits>

#define MAX_COUNT 101

using namespace std;

void InitialGraph(int N, int M, vector< vector<int>>& graph)
{
	for (int i = 0; i < M; ++i)
	{
		int row, col = 0;
		cin >> row >> col;
		graph[row-1][col-1] = 1;
		graph[col-1][row-1] = 1;
	}
}

void FloydWashall(int N, vector< vector<int>>& graph)
{
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

int FindShortestPath(int N, vector< vector<int>>& graph)
{
	int minKevinBacon = INT_MAX;
	int result = -1;

	for (int i = 0; i < N; ++i)
	{
		int kevinBaconSum = 0;
		for (int j = 0; j < N; ++j)
			kevinBaconSum += graph[i][j];
		
		if (kevinBaconSum < minKevinBacon)
		{
			minKevinBacon = kevinBaconSum;
			result = i + 1;
		}
	}

	return result;
}

int main()
{
	int N, M;

	cin >> N >> M;

	vector< vector<int>> studentGraph(M + 1, vector<int>(N + 1, MAX_COUNT));
	InitialGraph(N, M, studentGraph);

	FloydWashall(N, studentGraph);

	cout << FindShortestPath(N, studentGraph) << '\n';

	return 0;
}
