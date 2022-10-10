#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long int

bool is_Prime(ll num)
{
	if (num < 2) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;

	int sqrtn = sqrt(num);
	for (int div = 3; div <= sqrtn; ++div)
	{
		if (num % div == 0)
			return false;
	}

	return true;
}

string convert_num(int n, int k)
{
	string result = "";

	while (n > 0)
	{
		result += to_string(n % k);
		n /= k;
	}
	
	reverse(result.begin(), result.end());
	return result;
}

int getAnswer(string num)
{
	string tmp = "";
	int ret = 0;

	for (int i = 0; i < num.length(); ++i)
	{
		if (num[i] == '0' && !tmp.empty())
		{
			ll n = stoll(tmp);
			if (is_Prime(n))
				++ret;
			tmp = "";
		}
		else tmp += num[i];
	}
	if (!tmp.empty())
	{
		ll n = stoll(tmp);
		if (is_Prime(n))
			++ret;
	}

	return ret;
}

int solution(int n, int k) {
	int answer = -1;

	string num = convert_num(n, k);

	answer = getAnswer(num);

	return answer;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << solution(n, k);

	system("pause");
	return 0;
}