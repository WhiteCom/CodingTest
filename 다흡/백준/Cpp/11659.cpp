#include <iostream>
#include <vector>

using namespace std;

vector<int> CalculatePartialSum(vector<int>& nums)
{
	int length = nums.size();
	vector<int> partialSum(length + 1, 0); // 누적합을 저장할 배열

	// 누적합 계산
	for (int i = 1; i <= length; ++i)
	{
		partialSum[i] = partialSum[i - 1] + nums[i - 1];
	}

	return partialSum;
}

// 주어진 구간 [start, end]의 부분합을 반환하는 함수
int GetSubarraySum(vector<int>& partialSum, int start, int end)
{
	return partialSum[end+1] - partialSum[start];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int numbers, testCase;
	cin >> numbers >> testCase;

	vector<int> arr(numbers, 0);
	for (int i = 0; i < numbers; ++i)
	{
		cin >> arr[i];
	}

	vector<int> partialSum = CalculatePartialSum(arr);

	for (int i = 0; i < testCase; ++i)
	{
		int start, end;
		cin >> start >> end;
		int startIdx = start - 1;
		int endIdx = end - 1;
		int sum = 0;
		sum = GetSubarraySum(partialSum, startIdx, endIdx);

		cout << sum << '\n';
	}

	return 0;
}