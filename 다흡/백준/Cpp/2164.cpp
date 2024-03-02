#include <iostream>
#include <queue>

using namespace std;

bool IsLastData(queue<int>& q)
{
	if (q.size() == 1)
		return true;

	return false;
}

void ProcessQueue(queue<int>& q, bool flag)
{
	if (true == flag)
	{
		q.pop();
	}
	else
	{
		q.push(q.front());
		q.pop();
	}
}

int main()
{
	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; ++i)
		q.push(i);

	bool flag = true;
	while (!q.empty())
	{
		if (true == IsLastData(q))
		{
			cout << q.front() << '\n';
			break;
		}

		ProcessQueue(q, flag);
		flag = !flag;
	}
	return 0;
}