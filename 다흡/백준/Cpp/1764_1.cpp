#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BinarySearch(vector<string>& arr, vector<string>& result, int start, int end, string target)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;

	if (arr[mid] == target)
	{
		result.push_back(arr[mid]);
		return;
	}

	if (arr[mid] > target)
		BinarySearch(arr, result, start, mid - 1, target);
	else if(arr[mid] < target)
		BinarySearch(arr, result, mid + 1, end, target);
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> data_A(N, "");
	vector<string> data_B(M, "");
	vector<string> compare;

	for (int i = 0; i < N; ++i)
	{
		cin >> data_A[i];
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> data_B[i];
	}

	sort(data_A.begin(), data_A.end());
	sort(data_B.begin(), data_B.end());

	for (int i = 0; i < data_A.size(); ++i)
	{
		BinarySearch(data_B, compare, 0, M-1, data_A[i]);
	}

	cout << compare.size() << '\n';
	for (int i = 0; i < compare.size(); ++i)
	{
		cout << compare[i] << '\n';
	}


	return 0;
}