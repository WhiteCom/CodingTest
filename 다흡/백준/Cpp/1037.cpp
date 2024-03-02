#include <stdio.h>

void sort(int* inp, int n) //bubble
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (inp[i] > inp[j])
			{
				int temp = inp[i];
				inp[i] = inp[j];
				inp[j] = temp;
			}
		}
	}
}

void quickSort(int* arr, int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;

	for (; i <= j;)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	int num;
	scanf("%d", &num);
	int* arr = new int[num];

	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	//sort(arr, num);
	quickSort(arr, 0, num - 1);

	printf("%d\n", arr[0] * arr[num - 1]);

	delete arr;
	return 0;
}