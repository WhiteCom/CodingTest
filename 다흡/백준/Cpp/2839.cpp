#include <stdio.h>
#define MAX 9999

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int inp;
	scanf("%d", &inp);
	int* arr = new int[5001];

	for (int i = 0; i < 5001; i++)
		arr[i] = MAX;
	
	arr[3] = 1;
	arr[5] = 1;

	for (int i = 6; i <= 5000; i++)
	{
		arr[i] = min(arr[i - 3] + 1, arr[i - 5] + 1);
	}

	if (arr[inp] < MAX)
		printf("%d\n", arr[inp]);
	else
		printf("-1\n");

	delete arr;
	return 0;
}