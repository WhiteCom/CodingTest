#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// Input
	int numCount, testCase;
	cin >> numCount >> testCase;

	vector<int> numbers(numCount, 0);
	for (int i = 0; i < numCount; ++i)
		cin >> numbers[i];

	// 누적합 구하기
	vector<int> prefixSum(numCount + 1, 0);
	for (int i = 0; i < numCount; ++i)
	{
		prefixSum[i + 1] = prefixSum[i] + numbers[i];
	}

	// Calculate
	for (int i = 0; i < testCase; ++i)
	{
		int start, end;
		cin >> start >> end;

		if (start == end)
			cout << numbers[start - 1] << '\n';
		else if (start == 1)
			cout << prefixSum[end] << '\n';
		else
			cout << prefixSum[end] - prefixSum[start - 1] << '\n';
	}

	return 0;
}