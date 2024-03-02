#include <stdio.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int d = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
		int r = (r1 + r2) * (r1 + r2);
		int r3 = (r1 - r2) * (r1 - r2);

		//printf("d,r,r3 : %d %d %d\n", d, r, r3);

		if (d != 0)
		{
			if (d < r && d > r3)
				printf("2\n");
			else if (d == r || d == r3)
				printf("1\n");
			else if (d > r || d < r3)
				printf("0\n");
		}
		else {
			if (r1 != r2)
				printf("0\n");
			else if (r1 == r2)
				printf("-1\n");

		}
	}

	return 0;
}