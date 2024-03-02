#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MergeSort(vector<int>& arr, int low, int high, vector<int>& result)
{
	// base condition
	if (low >= high)
		return;

	// divide
	int mid = (low + high) / 2;

	// conquer
	MergeSort(arr, low, mid, result);
	MergeSort(arr, mid + 1, high, result);

	// combine.
	int i = low, j = mid + 1, k = low;
	for (; k <= high; ++k)
	{
		if (j > high)
			result[k] = arr[i++];
		else if (i > mid)
			result[k] = arr[j++];
		else if (arr[i] <= arr[j])
			result[k] = arr[i++];
		else
			result[k] = arr[j++];
	}

	// copy
	for (int i = low; i <= high; ++i)
		arr[i] = result[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num;
	cin >> num;
	vector<int> arr(num, 0);
	for (int i = 0; i < num; ++i)
		cin >> arr[i];

	vector<int> result(num, 0);
	MergeSort(arr, 0, arr.size() - 1, result);

	for (int i = 0; i < num; ++i)
		cout << arr[i] << '\n';
	return 0;
}