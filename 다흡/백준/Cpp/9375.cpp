#include <iostream>
#include <map>
#include <string>

using namespace std;

int CountOutfitCombinations(map<string, int>& clothes)
{
	int combinations = 1;

	// 모든 의상 조합 계산 
	// 0가지 선택 => 게산식에서 이 경우로 인해, it->second + 1 이 붙음.
	// 1가지 선택
	// ...
	// n가지 선택

	// 각 의상 종류별로 선택가능한 경우의 수를 계산하여 모두 곱함
	map<string, int>::iterator it;
	for (it = clothes.begin(); it != clothes.end(); ++it)
	{
		combinations *= (it->second + 1);
	}

	// 아무 의상도 입지 않는 경우를 제외한 결과 반환
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