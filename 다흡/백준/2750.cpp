#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int arr[2][1001] = { 0, }; //양수, 음수
	
	for (int i = 0; i < n;i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp < 0)
			arr[0][tmp * -1]++;
		else
			arr[1][tmp]++;
	}

	for (int j = 0; j < 2; j++)
	{
		if (j == 0) //음수
		{
			for (int i = 1000; i > -1; i--)
			{
				if(arr[j][i] > 0)
					printf("%d\n", i * -1);
			}
		}
		else //if (j == 1) //양수
		{
			for (int i = 0; i < 1001; i++)
			{
				if (arr[j][i] > 0)
					printf("%d\n", i);
			}
		}
	}

	return 0;
}