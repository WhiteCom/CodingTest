#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main()
{
	int r;
	scanf("%d", &r);
	double u_circle = (double)(r * r * PI);
	double t_w = (double)(2 * r * r);
	double t_circle = t_w * t_w;
	printf("%lf\n%lf\n", u_circle, t_circle);
	return 0;
}