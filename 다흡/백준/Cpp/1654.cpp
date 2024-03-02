#include <iostream>
#include <vector>

#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

long long BinarySearch(vector<int>& arr, long long low, long long high, int target)
{
	long long result = 0;

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long count = 0;

		for (long long i = 0; i < arr.size(); ++i)
		{
			count += arr[i] / mid;
		}

		if (count >= target)
		{
			low = mid + 1;
			if(result < mid)
				result = mid;
		}
		else
			high = mid - 1;
	}

	return result;
}

int main()
{
	int K, N;
	cin >> K >> N;

	long long minNum = 1;
	long long maxNum = 0;
	vector<int> inputData(K, 0);
	for (long long i = 0; i < K; ++i)
	{
		cin >> inputData[i];
		maxNum = max(maxNum, inputData[i]);
	}

	long long result = BinarySearch(inputData, minNum, maxNum, N);
	cout << result << '\n';

	return 0;
}