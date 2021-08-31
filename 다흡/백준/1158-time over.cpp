#include <stdio.h>

struct arr
{
	arr* prev;
	int n;
};

arr* inp;
int last;

void add(int num)
{
	arr* tmp = new arr();
	tmp->prev = inp;
	tmp->n = num;

	inp = tmp;
	last++;
}

arr* findFirst()
{
	arr* tmp = inp;
	for (; tmp->prev;)
	{

		tmp = tmp->prev;
	}
	return tmp;
}

void remove(int index)
{
	arr* node = inp;
	arr* nNode = NULL;
	int goal = last - 1;
	for (int i = 1; node; i++)
	{
		if (goal == index)
		{
			if (i == 1) //마지막 인덱스 삭제인경우
			{
				arr* tmp = node->prev;
				delete node;
				last--;
				inp = tmp;
				break;
			}
			else
			{
				nNode->prev = node->prev;
				delete node;
				last--;
				break;

			}
		}
		nNode = node;
		node = node->prev;
		goal--;
	}
}

int main()
{
	int N, K, i;
	scanf("%d %d", &N, &K);

	int* val = new int[N];
	int valNum = 0;

	inp = NULL; //empty node

	for (i = 0; i < N; i++)
	{
		add(i + 1);
	}

	arr* tmp = inp;
	for (i = 1; tmp; i++)
	{
		if (valNum >= N) break;

		if (i % K == 0) //remove
		{
			arr* tmp2 = findFirst();
			val[valNum] = tmp2->n;
			valNum++;
			remove(0);
			continue;
		}
		arr* tmp2 = findFirst();
		add(tmp2->n);
		remove(0);
	}

	printf("<");
	for (int i = 0; i < valNum; i++)
	{
		if (i == valNum - 1)
		{
			printf("%d>", val[i]);
			break;
		}
		printf("%d, ", val[i]);
	}

	for (; inp;)
	{
		arr* tmp = inp->prev;
		delete inp;
		inp = tmp;
	}

	return 0;
}
