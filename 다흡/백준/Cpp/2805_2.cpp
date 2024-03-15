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

	// ���� �ڸ��� ���� ������ ���� ��ǥ���̸�ŭ �Ǵ� ���
	if (_length >= targetLength)
	{
		// ���� ���̺��� ���� �߰��� ���� �� ū ��� ����
		if(result < mid)
			result = mid;
	}

	// ���̸� ������ų �� ���� ��
	if (_length > targetLength)
		BinarySearch(trees, mid + 1, end, targetLength, result);
	
	// ���̸� ���ҽ��Ѿ� �� ��
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