#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	queue<int> arr;
	for (int i = 0; i < N; i++)
	{
		arr.push(i + 1);
	}

	printf("<");
	for (int i = 1; !arr.empty(); i++)
	{
		if (i % K == 0)
		{
			printf("%d", arr.front());
			if (arr.size() != 1)
				printf(", ");
			arr.pop();
			continue;
		}
		arr.push(arr.front());
		arr.pop();
	}
	printf(">");
		
	return 0;
}