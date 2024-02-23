#include <iostream>
#include <vector>

#define MAX_NUM 1000001

using namespace std;

void PrimeNumbers(vector<bool>& numbers)
{
	for (int i = 2; i * i < MAX_NUM; ++i)
	{
		if (numbers[i] == true)
		{
			for (int j = i * i; j < MAX_NUM; j += i)
				numbers[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<bool> numbers(MAX_NUM, true);
	numbers[0] = false;
	numbers[1] = false;
	
	PrimeNumbers(numbers);

	int count = 0;
	for(int i=N; i<=M; ++i)
	{
		if (numbers[i])
			cout << i << '\n';
	}

	return 0;
}