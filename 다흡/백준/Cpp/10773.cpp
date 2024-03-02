#include <stdio.h>
#define MAX 100001

int* arr;
int last;

void push(int num)
{
	arr[last] = num;
	last++;
}

void pop()
{
	arr[last] = 0;
	last--;
}

int main()
{
	int K, i;
	scanf("%d", &K);
	arr = new int[MAX];

	for (i = 0; i < K; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp != 0)
			push(tmp);
		else
			pop();
	}

	int sum = 0;
	for (i = 0; i < last; i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);

	return 0;
}
