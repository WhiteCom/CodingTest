#include <iostream>
#include <vector>

using namespace std;

// Solution 1) Simple Recursion
// Time limit error
int combination1(int n, int r)
{
	if (r == 0 || n == r)
		return 1;

	return combination1(n - 1, r - 1) + combination1(n - 1, r);
}

// Solution 2) Dynamic Programming : Recursion
int combination2(int n, int r, vector< vector<int>>& memo)
{
	if (r == 0 || n == r)
		return 1;

	if (memo[n][r] != -1)
		return memo[n][r];

	memo[n][r] = combination2(n - 1, r - 1, memo) + combination2(n - 1, r, memo);
	return memo[n][r];
}

// Solution 3) Dynamic Programming : Bottom-up
int combination3(int n, int r)
{
	int greaterNum = n > r ? n : r;
	int minNum = greaterNum == n ? r : n;
	vector< vector<int>> memo(greaterNum + 1, vector<int>(minNum + 1, -1));

	// preprocess :  nCr : n == r
	for (int i = 0; i < greaterNum + 1; ++i)
	{
		memo[i][0] = 1;
		if(i <= minNum)
			memo[i][i] = 1;
	}

	// Bottom-up
	for (int i = 1; i <= greaterNum; ++i)
	{
		for (int j = 1; j <= minNum; ++j)
		{
			if (memo[i][j] != -1)
				continue;

			memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
		}
	}

	return memo[greaterNum][minNum];
}


int func(int n1, int n2)
{
	int greaterNum = n1 > n2 ? n1 : n2;
	int r = n1 == greaterNum ? n2 : n1;

	vector< vector<int>> memo(greaterNum + 1, vector<int>(r + 1, -1));

	//int result = combination(greaterNum, r);
	int result = combination2(greaterNum, r, memo);
	return result;
}

int main()
{
	int T, n, m;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> n >> m;
		//cout << func(n, m) << '\n';
		cout << combination3(n, m) << '\n';
	}
	
	return 0;
}