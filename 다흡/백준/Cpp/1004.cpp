#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int planet;
		scanf("%d", &planet);

		int result = 0;
		for (int j = 0; j < planet; j++)
		{
			int cx, cy, r;
			scanf("%d %d %d", &cx, &cy, &r);
			int d1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
			int d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);

			if (r * r > d1 && r * r > d2)
				continue;

			result += d1 > (r * r) ? 0 : 1;
			result += d2 > (r * r) ? 0 : 1;
		}
		printf("%d\n", result);
	}

	return 0;
}