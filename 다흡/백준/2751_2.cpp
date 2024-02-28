#include <iostream>
#include <vector>

using namespace std;

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void Downheap(vector<int>& arr, int cur, int k)
{
	int left, right, p;
	while (cur < k)
	{
		left = cur * 2 + 1;
		right = cur * 2 + 2;

		if (left >= k && right >= k)
			break;

		p = cur;
		if (left < k && arr[p] < arr[left])
			p = left;
		if (right < k && arr[p] < arr[right])
			p = right;
		if (p == cur)
			break;

		swap(arr[cur], arr[p]);
		cur = p;
	}
}

void Heapify(vector<int>& arr, int n)
{
	int i, p;
	for (i = (n - 1) / 2; i >= 0; --i)
	{
		Downheap(arr, i, n);
	}
}

void HeapSort(vector<int>& arr, int num)
{
	int k;
	Heapify(arr, num);
	for (k = num - 1; k > 0; --k)
	{
		swap(arr[0], arr[k]);
		Downheap(arr, 0, k);
	}
}

int main()
{
	int num;
	cin >> num; 
	vector<int> arr(num, 0);
	for (int i = 0; i < num; ++i)
		cin >> arr[i];

	HeapSort(arr, num);
	for (int i = 0; i < num; ++i)
		cout << arr[i] << '\n';

	return 0;
}