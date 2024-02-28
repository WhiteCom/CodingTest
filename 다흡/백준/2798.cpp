#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num, maxNum;
	cin >> num >> maxNum;
	vector<int> arr(num, 0);
	for (int i = 0; i < num; ++i)
		cin >> arr[i];

	// Select Card
	vector<int> result(4, 0); // last : sum
	for (int i = 0; i < num - 2; ++i)
	{
		int tempSum = 0;
		for (int j = i + 1; j < num - 1; ++j)
		{
			for (int k = j + 1; k < num; ++k)
			{
				tempSum = arr[i] + arr[j] + arr[k];
				if (tempSum <= maxNum && tempSum > result[3])
				{
					result[0] = arr[i];
					result[1] = arr[j];
					result[2] = arr[k];
					result[3] = tempSum;
				}
			}
		}
	}

	int resultSum = 0;
	for (int i = 0; i < 3; ++i)
		resultSum += result[i];

	cout << resultSum << '\n';
	return 0;
}