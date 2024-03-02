#include <iostream>

#define MAX_NUM 1000000

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= MAX_NUM; ++i)
	{
		int result = 0;
		int num = i;
		while (num > 0)
		{
			result += num % 10;
			num /= 10;
		}

		result += i;
		if (result == N)
		{
			cout << i << '\n';
			return 0;
		}
	}

	cout << "0\n";

	return 0;
}