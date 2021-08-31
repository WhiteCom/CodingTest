#include <stdio.h>
#include <stack>
using namespace std;

/*
괄호 짝 맞추는 문제 = 스택
( : 여는괄호 = push
) : 닫는괄호 = pop 
의미로 해석하면 본 문제 수월히 풀 것. 
(문자열 처리를 기본적으로 할 수 있다는 전제하에)
*/
int main()
{
	int c = 0; //소괄호 c
	int d = 0; //대괄호 d

	char ch[200] = { 0, };
	while (1)
	{
		for (int i = 0;; i++)
		{
			scanf("%c", &ch[i]);
			if (ch[i] == '.') break;
			else if (ch[i] == '\n')
			{
				i--;
				continue;
			}
		}

		if (ch[0] == '.') break;

		stack<char> inp;
		c = 0, d = 0;
		for (int i = 0;; i++)
		{
			if (ch[i] == '(')
			{
				c++;
				inp.push(ch[i]);
			}
			else if (ch[i] == ')')
			{
				c--;
				if (!inp.empty() && inp.top() == '(')
				{
					inp.pop();
				}
				else
				{
					printf("no\n");
					break;
				}
			}

			if (ch[i] == '[')
			{
				d++;
				inp.push(ch[i]);
			}
			else if (ch[i] == ']')
			{
				d--;
				if (!inp.empty() && inp.top() == '[') inp.pop();
				else
				{
					printf("no\n");
					break;
				}
			}

			if(ch[i] == '.') 
			{
				if (c == 0 && d == 0)
				{
					printf("yes\n");
				}
				else 
					printf("no\n");
				
				break;
			}
		}
	}
	return 0;
}