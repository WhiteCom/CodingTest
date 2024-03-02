#include <stdio.h>

int map[8 * 8]
{
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 1,
	1, 0, 1, 0, 1, 0, 1, 0,
};

int main()
{
	char* inp = new char[8 * 8];

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++) 
			scanf("%c", &inp[8 * j + i]);
		
		getchar();
	}
	
	int cnt = 0;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (map[j * 8 + i] == 0 && inp[j * 8 + i] == 'F')
				cnt++;
		}
	}
	printf("%d\n", cnt);

	delete inp;
	return 0;
}