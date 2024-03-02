#include <stdio.h>

//2577¹ø 
char* itoa(int i)
{
	char* buf = new char[11];
	sprintf(buf, "%d", i);
	return buf;
}

int main()
{
	int a, b, c, abc;
	char* s = new char[11];
	scanf("%d %d %d", &a, &b, &c);

	abc = a * b * c;
	s = itoa(abc);

	int arr[10] = { 0, }; //0~9±îÁö
	for (int i = 0; s[i]; i++)
	{
		switch (s[i])
		{
		case '0': arr[0]++; break;
		case '1': arr[1]++; break;
		case '2': arr[2]++; break;
		case '3': arr[3]++; break;
		case '4': arr[4]++; break;
		case '5': arr[5]++; break;
		case '6': arr[6]++; break;
		case '7': arr[7]++; break;
		case '8': arr[8]++; break;
		case '9': arr[9]++; break;
		default: break;
		}
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return 0;
}