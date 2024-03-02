#include <stdio.h>
#define MAX_T 2147483647
/*
입력받은 땅의 최저 높이에서 최고 높이까지 모든 높이를 탐색하면서 걸리는 시간의 최소를 찾으면 되는 문제이다.
현재 탐색하는 높이를 h라고 두자. 모든 땅을 하나씩 보면서 h와의 차이에 따라 시간을 계산하면 된다.
땅의 높이가 h보다 높은지 낮은지에 따라 각각 합을 구한다.

쌓아야 되는 블록의 수가, 제거한 수와 기존 블록의 수의 합보다 작으면 해당 높이로 만들 수 없으므로 넘어간다.
해당 높이로 만들 수 있다면, 작업에 소요되는 최소 시간을 구한다.
시간에 따라 최대 높이를 구해야 하므로 같은 시간이 걸리더라도 높이가 높다면 높이 역시 바꿔준다.
*/

int* arr;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M, B, i, j;
	scanf("%d %d %d", &N, &M, &B);
	arr = new int[N * M];
	for (i = 0; i < N * M; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int remove = 0, add = 0, leastTime = MAX_T, mostHeight = 0, h;
	for (j = 0; j < 257; j++)
	{
		h = j; //현재 벽 높이s
		add = 0;
		remove = 0;
		for (i = 0; i < N * M; i++)
		{
			if (arr[i] - h > 0) //높은경우
				remove += (arr[i] - h);
			else if(arr[i] - h < 0)//낮은경우
				add -= (arr[i] - h);
		}

		if (remove + B >= add)
		{
			int time = remove * 2 + add;
			if (leastTime >= time)
			{
				leastTime = time;
				mostHeight = h;
			}
		}
	}


	printf("result : %d %d", leastTime, mostHeight);

	delete arr;
	return 0;
}
