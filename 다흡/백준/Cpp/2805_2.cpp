#include <iostream>
#include <vector>

using namespace std;

void BinarySearch(vector<int>& trees, int start, int end, long long targetLength, long long& result)
{
	if (start > end)
		return;

	int mid = (start + end) / 2;

	long long _length = 0;
	for (int i = 0; i < trees.size(); ++i)
	{
		_length += (trees[i] - mid) > 0 ? (trees[i] - mid) : 0;
	}

	// 나무 자르고 남은 길이의 합이 목표길이만큼 되는 경우
	if (_length >= targetLength)
	{
		// 기존 길이보다 새로 발견한 값이 더 큰 경우 갱신
		if(result < mid)
			result = mid;
	}

	// 길이를 증가시킬 수 있을 때
	if (_length > targetLength)
		BinarySearch(trees, mid + 1, end, targetLength, result);
	
	// 길이를 감소시켜야 할 때
	else
		BinarySearch(trees, start, mid - 1, targetLength, result);
}

int main()
{
	int treeCount;
	long long targetLength;
	cin >> treeCount >> targetLength;

	vector<int> treeContainer(treeCount, 0);
	int maxTree = 0;
	for (int i = 0; i < treeCount; ++i)
	{
		cin >> treeContainer[i];
		if (maxTree < treeContainer[i])
			maxTree = treeContainer[i];
	}

	long long maxLength = -1;
	BinarySearch(treeContainer, 0, maxTree, targetLength, maxLength);

	cout << maxLength << '\n';

	return 0;
}