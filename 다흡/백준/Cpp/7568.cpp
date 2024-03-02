#include <stdio.h>

struct pair
{
	int wei;
	int hei;
};

bool max(pair a, pair b)
{
	if (a.wei < b.wei && a.hei < b.hei)
		return true;

	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	pair* arr = new pair[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].wei, &arr[i].hei);

	
	int* result = new int[n];
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		pair tmp;
		tmp.wei = 0;
		tmp.hei = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			if (max(arr[i], arr[j]))
				cnt++;
		}
		result[i] = cnt;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);

	delete arr;
	delete result;
	return 0;
}