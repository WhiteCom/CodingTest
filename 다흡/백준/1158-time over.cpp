#include <stdio.h>

struct Node
{
	int data;
	Node* link;
};

struct Queue
{
	Node* front, * rear;
};

Queue* createQueue()
{
	Queue* q = new Queue;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int isEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;

	return 0;
}

void enQueue(Queue* q, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->link = NULL;
	if (q->front == NULL)
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->link = temp;
		q->rear = temp;
	}
}

int deQueue(Queue* q)
{
	Node* last = q->front;
	int data;
	if (isEmpty(q))
		return -1;
	else
	{
		data = last->data;
		q->front = q->front->link;
		if (q->front == NULL)
		{
			q->rear = NULL;
		}
		delete last;
		return data;
	}
}

void printQueue(Queue* q)
{
	Node* temp = q->front;
	printf("link Q : ");
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	Queue* q = createQueue();
	for (int i = 1; i <= n; i++)
		enQueue(q, i);

	int cnt = 1;
	printf("<");
	while (n > 1)
	{
		if (cnt == k)
		{
			cnt = 1;
			printf("%d, ", deQueue(q));
			n--;
			continue;
		}

		enQueue(q, deQueue(q));
		cnt++;
	}
	printf("%d>", deQueue(q));

	return 0;
}