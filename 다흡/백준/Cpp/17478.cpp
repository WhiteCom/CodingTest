#include <iostream>

using namespace std;

//=======================================================
// https://www.acmicpc.net/problem/17478
//=======================================================

void recursive(int N, int count)
{
	for (int i = 0; i < count * 4; i++)
	{
		cout << "_";
	}
	cout << "\"����Լ��� ������?\"\n";

	if (count == N)
	{
		for (int i = 0; i < count * 4; i++)
		{
			cout << "_";
		}
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else
	{
		for (int i = 0; i < count * 4; i++)
		{
			cout << "_";
		}
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < count * 4; i++)
		{
			cout << "_";
		}
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < count * 4; i++)
		{
			cout << "_";
		}
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		recursive(N, count + 1);
	}
	for (int i = 0; i < count * 4; i++)
	{
		cout << "_";
	}
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	
	recursive(N, 0);

	return 0;
}