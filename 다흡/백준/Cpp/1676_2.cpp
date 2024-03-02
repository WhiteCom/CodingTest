#include <iostream>
#include <vector>

#define MAX_NUMBER 1200

using namespace std;

int Multiply(int x, vector<int>& res, int res_size)
{
	int result = res_size;
	int carry = 0;

	for (int i = 0; i < result; ++i)
	{
		int prod = res[i] * x + carry;

		res[i] = prod % 10;
		carry = prod / 10;
	}

	while (carry)
	{
		res[result] = carry % 10;
		carry /= 10;
		result++;
	}

	return result;
}

int Factorial(int num)
{
	vector<int> res(MAX_NUMBER, 0);

	res[0] = 1;
	int res_size = 1;

	for (int x = 2; x <= num; ++x)
	{
		res_size = Multiply(x, res, res_size);
	}

	int count = 0;
	for (int i = 0; i<res_size && res[i] == 0; ++i)
	{
		count++;
	}

	return count;
}

int main()
{
	int N;
	cin >> N;

	int result = Factorial(N);
	cout << result << '\n';

	return 0;
}