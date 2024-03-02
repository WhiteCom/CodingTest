#include <stdio.h>

int strlen(char* s)
{
	int len = 0;
	for (int i = 0; s[i]; i++)
		len++;
	return len;
}

void reverse(int len, char* s)
{
	int _len = len / 2;
	for (int i = 0; i < _len; i++)
	{
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

int main()
{
	char* a = new char[100000] { NULL, };
	char* b = new char[100000]{ NULL, };
	char* result = new char[100001]{ NULL, };
	int lenA = 0, lenB = 0, i;

	//input
	for (i = 0;; i++)
	{
		scanf("%c", &a[i]);
		if (a[i] == ' ')
		{
			a[i] = NULL;
			break;
		}
	}
	lenA = i;

	scanf("%s", b);
	lenB = strlen(b);

	reverse(lenA, a);
	reverse(lenB, b);

	int upperNum = 0; //올림수
  	for (i = 0;;i++)
	{
		if (!a[i] && !b[i])
		{
			if (upperNum > 0)
				result[i] = upperNum + '0';
			break;
		}
		if (!a[i]) //a가 더이상 없을때
		{
			int tmp;
			tmp = upperNum + (b[i] - '0');
			if (tmp >= 10)
			{
				upperNum = tmp / 10;
				tmp %= 10;
			}
			else
				upperNum = 0;
			result[i] = tmp + '0';
		}
		else if (!b[i]) //b가 더이상없을때
		{
			int tmp;
			tmp = upperNum + (a[i] - '0');
			if (tmp >= 10)
			{
				upperNum = tmp / 10;
				tmp %= 10;
			}
			else
				upperNum = 0;
			result[i] = tmp + '0';
		}
		else //둘다 있을때
		{
			int tmp;
			tmp = upperNum + (a[i] - '0') + (b[i] - '0');
			if (tmp >= 10)
			{
				upperNum = tmp / 10;
				tmp %= 10;
			}
			else
				upperNum = 0;
			result[i] = tmp + '0';
		}
	}

	int lenC = strlen(result);

	reverse(lenC, result);
	printf("%s", result);

	delete a;
	delete b;
	delete result;
	return 0;
}