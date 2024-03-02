#include <stdio.h>

int* sorted = NULL;

void merge(int* arr, int start, int mid, int end)
{
	int i, j, k, tmp;
	i = start; 
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > mid)
		for (tmp = j; tmp <= end; tmp++, k++)
			sorted[k] = arr[tmp];

	else
		for (tmp = i; tmp <= mid; tmp++, k++)
			sorted[k] = arr[tmp];

	for (tmp = start; tmp <= end; tmp++)
		arr[tmp] = sorted[tmp];
		

}

void mergeSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

#if 0 // 이 문제에서는 시간초과 발생
void quickSort(int* arr, int start, int end)
{
	int low = start, high = end;
	int mid = (start + end) / 2;
	int temp;

	if (low <= high)
	{
		while (arr[low] < arr[mid])
			low++;
		while (arr[high] > arr[mid])
			high--;

		if (low <= high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	}
	if (low < end)
		quickSort(arr, low, end);
	if (start < high)
		quickSort(arr, start, high);
}
#endif

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	sorted = new int[n+1];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	mergeSort(arr, 0, n - 1);
	//quickSort(arr, 0, n - 1);

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			result += arr[j];
	}
	printf("%d\n", result);

	delete arr;
	delete sorted;

	return 0;
}