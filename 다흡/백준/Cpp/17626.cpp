#include <iostream>
#include <vector>

#define min(num1, num2) (num1) < (num2) ? (num1) : (num2)

using namespace std;

int main()
{
	int num;
	cin >> num;

	// DP 
	vector<int> dp(num + 1, 0);

	/*
	모든 자연수가 넷 혹은 그 이하의 제곱수의 합으로 표현가능하다는 증명
	*/
	dp[1] = 1;
	for (int i = 2; i <= num; ++i)
	{
		int minCount = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; ++j)
		{
			// 자신보다 작은 모든 제곱수들을 탐색하면서 최소갯수 체크
			int temp = i - j * j;
			if (temp < 0)
				break;
			minCount = min(minCount, dp[temp]);
		}
		dp[i] = minCount + 1;
	}

	cout << dp[num] << '\n';

	return 0;
}