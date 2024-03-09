#include <iostream>
#include <vector>

#define MAX_DISTANCE 500001
#define min(num1, num2) (num1) < (num2) ? (num1) : (num2)

using namespace std;

int main()
{
	int userCount, relationCount;
	cin >> userCount >> relationCount;

	// Init Graph
	vector< vector<int>> userGraph(userCount + 1, vector<int>(userCount + 1, 0));
	for (int i = 0; i < relationCount; ++i)
	{
		int startUser, endUser;
		cin >> startUser >> endUser;
		userGraph[startUser][endUser] = 1;
		userGraph[endUser][startUser] = 1;
	}

	vector< vector<int>> distance(userCount, vector<int>(userCount, MAX_DISTANCE));

	// Init Distance
	for (int i = 1; i <= userCount; ++i)
	{
		for (int j = 1; j <= userCount; ++j)
		{
			if (userGraph[i][j] == 1 && userGraph[j][i] == 1)
			{
				distance[i - 1][j - 1] = 1;
				distance[j - 1][i - 1] = 1;
			}
		}
	}

	// Floyd Warshall
	for (int k = 0; k < userCount; ++k)
	{
		for (int i = 0; i < userCount; ++i)
		{
			for (int j = 0; j < userCount; ++j)
			{
				if (i == j)
					continue;

				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}

	// Calculate
	vector<int> distanceSum(userCount, 0);
	for (int i = 0; i < userCount; ++i)
	{
		for (int j = 0; j < userCount; ++j)
		{
			if (distance[i][j] >= MAX_DISTANCE)
				continue;

			distanceSum[i] += distance[i][j];
		}
	}
	
	// Find MinValue Index
	int minValue = MAX_DISTANCE;
	int minIndex = 0;
	for (int i = 0; i < userCount; ++i)
	{
		if (minValue > distanceSum[i])
		{
			minValue = distanceSum[i];
			minIndex = i + 1;
		}
	}

	cout << minIndex << '\n';
	

	return 0;
}