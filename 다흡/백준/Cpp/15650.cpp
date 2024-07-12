#include <iostream>
#include <vector>

#define MAX_NUM 8

using namespace std;

// nPr n 개 중에서 r개의 중복포함 모든 조합을 찾는 코드

void DFS(vector<int>& arr, vector<bool>& visited, int count, int num, int m, int n)
{
	if (count == n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= m; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			arr[count] = i;
			DFS(arr, visited, count + 1, i + 1, m, n);
			visited[i] = false;
		}
	}
}

int main()
{
	int m, n;
	cin >> m >> n;

	vector<int> arr(MAX_NUM, 0);
	vector<bool> visited(MAX_NUM, false);
	DFS(arr, visited, 0, 1, m, n);
	return 0;
}