#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase; 

	/*
	(i >= 5)
	dp[i] = dp[i-1] + dp[i-5]
	*/

	vector<long> dp(101, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 100; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	for (int i = 0; i < testCase; ++i)
	{
		int N;
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}