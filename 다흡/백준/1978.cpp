#include <iostream>
#include <vector>

#define MAX_RANGE 1001

using namespace std;

int main()
{
	// Find Prime Number in range 1 ~ 100
	vector<bool> numbers(MAX_RANGE, true);
	numbers[0] = false;
	numbers[1] = false;

	for (int i = 1; i * i < MAX_RANGE; ++i)
	{
		if (numbers[i] == true)
		{
			for (int j = i * i; j < MAX_RANGE; j += i)
				numbers[j] = false;
		}
	}

	// Count Prime Number
	int count = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tempNum;
		cin >> tempNum;
		if (numbers[tempNum] == true)
			count++;
	}

	cout << count << '\n';

	return 0;
}