#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> numbers(n, 0);

	double sum = 0;
	int maxValue = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
		if (maxValue < numbers[i])
			maxValue = numbers[i];
	}

	// initial 
	for (int i = 0; i < n; ++i)
	{
		sum += static_cast<double>(numbers[i]) / maxValue * 100;
 	}

	double divideNum = 0.0;
	divideNum = sum / n;
	cout << divideNum << '\n';

	return 0;
}