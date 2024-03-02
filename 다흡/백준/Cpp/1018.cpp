#include <stdio.h>

const char white[8][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};

const char black[8][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};


int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M, i, j, x, y, tmp;
	scanf("%d %d", &N, &M);
	char inp[51][51];

	for (j = 0; j < N; j++)
	{
		scanf("%s", inp[j]);
	}

	int b_min = 0, w_min = 0; //흑 백 각각의 경우에 최소로 칠할 정사각형 개수
	int result = 0;
	int val = 99999;
	for (j = 0; j+8 <= N; j++)
	{
		for (i = 0; i+8 <= M; i++)
		{
			b_min = 0;
			w_min = 0;
			for (y = 0; y < 8; y++)
			{
				for (x = 0; x < 8; x++)
				{
					if (inp[j + y][i + x] != black[y][x])
					{
						b_min++;
					}
					if (inp[j + y][i + x] != white[y][x])
					{
						w_min++;
					}
				}
			}
			
			result = min(w_min, b_min);
			val = min(val, result);
		}
	}
	
	printf("%d\n", val);

	return 0;
}