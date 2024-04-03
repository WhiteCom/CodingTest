#include <iostream>
#include <map>
#include <string>

using namespace std;

int CountOutfitCombinations(map<string, int>& clothes)
{
	int combinations = 1;

	// ��� �ǻ� ���� ��� 
	// 0���� ���� => �Ի�Ŀ��� �� ���� ����, it->second + 1 �� ����.
	// 1���� ����
	// ...
	// n���� ����

	// �� �ǻ� �������� ���ð����� ����� ���� ����Ͽ� ��� ����
	map<string, int>::iterator it;
	for (it = clothes.begin(); it != clothes.end(); ++it)
	{
		combinations *= (it->second + 1);
	}

	// �ƹ� �ǻ� ���� �ʴ� ��츦 ������ ��� ��ȯ
	return combinations - 1;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int n;
		cin >> n;

		map<string, int> clothes;
		for (int j = 0; j < n; ++j)
		{
			string name, type;
			cin >> name >> type;
			clothes[type]++;
		}

		int resultCombination = CountOutfitCombinations(clothes);
		cout << resultCombination << '\n';
	}

	return 0;
}