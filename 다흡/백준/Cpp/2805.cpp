#include <stdio.h>
#define max(a, b) a > b ? a : b

long long int binSearch(long long int* arr, long long int n, long long int start, long long int end, long long int target)
{
	long long int left = start, right = end;
	long long int result = 0;
	while (left <= right)
	{
		long long int sum = 0;
		long long int mid = (left + right) / 2;

		for (long long int i = 0; i < n; i++)
		{
			sum += arr[i] - mid > 0 ? arr[i] - mid : 0;
		}
		if (sum >= target)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return result;
}

int main()
{
	long long int n, m;
	scanf("%lld %lld", &n, &m);

	long long int* arr = new long long int[n];

	long long int MAX = 0;
	for (long long int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		MAX = max(MAX, arr[i]);
	}

	long long int result = binSearch(arr, n, 0, MAX, m);
	printf("%lld\n", result);


	delete arr;
	return 0;
}