#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
문자열 집합이 주어진다.
이 때, 이 집합 내, 어떤 문자열이 집합 내 다른 문자열의 접두사가 되지 않는 부분집합 중, 
부분집합의 크기를 최대값을 구하는 문제.

이 문제는 가능하면 아래 구현된 코드를 직접 디버깅하면서 이해해봐야 빠르다. 
*/

int main()
{
	int n;
	cin >> n;

	vector<string> vec_str(n, "");
	vector<bool> check(n, true);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec_str[i];
	}

	sort(vec_str.begin(), vec_str.end());

	for (int i = 0; i < vec_str.size(); ++i)
	{
		for (int j = i + 1; j < vec_str.size(); ++j)
		{
			string temp_str1 = vec_str[j].substr(0, vec_str[i].length());
			string temp_str2 = vec_str[i];
			if (temp_str1 == temp_str2)
			{
				check[i] = false;
				break;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i] == true)
			answer++;
	}

	cout << answer << '\n';

	return 0;
}