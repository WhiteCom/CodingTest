#include <iostream>
#include <vector>
#include <string>

#define MAX_VALUE 50

using namespace std;

/*
���Ʈ���� + ��ѱ��� ���� �˰��� �̿�

* ��ѱ��� ����
- N ���� ��ѱ� ���� N+1 ��ѱⰡ �ִٸ�, ������ 2���� �̻��� ���� �����Ѵ�.
- MBTI�� 16���� ������ 17���� �����Ѵٸ�, ������ 2���� MBTI �� ��ģ��.
- ���� N > 32 �� ���, MBTI�� ������ ����� 3�� �����Ѵ�. (�̶��� �� ������ ������� �����ϰ� �ǰ�, �ּ� �ɸ��� �Ÿ� 0�� ��)
*/

int FindDistance(string& str1, string& str2)
{
	int result = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (str1[i] != str2[i])
			result++;
	}

	return result;
}

int FindResult(vector<string>& arr)
{
	int result = MAX_VALUE;

	int arrLength = arr.size();

	for (int i = 0; i < arrLength - 2; ++i)
	{
		for (int j = i + 1; j < arrLength - 1; ++j)
		{
			for (int k = j + 1; k < arrLength; ++k)
			{
				int distance1 = FindDistance(arr[i], arr[j]);
				int distance2 = FindDistance(arr[i], arr[k]);
				int distance3 = FindDistance(arr[j], arr[k]);
				int distanceSum = distance1 + distance2 + distance3;

				result = result > distanceSum ? distanceSum : result;
			}
		}
	}

	return result;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int N;
		cin >> N;

		// ��ѱ��� ������ ���� �Ʒ��� ���� �з���
		// 1. N > 2 * MBTI_COUNT : ���� MBTI 3�� ����
		// 2. N > 1 * MBTI_COUNT : ���� MBTI 2�� ���� => �� ������ ���� ���غ�
		// 3. �� �ܴ� ���� �ٸ� MBTI ���� �� ����.

		// 1. MBTI ������ ��� 3���̻��� ������ ������ ���

		vector<string> MBTI_container;
		for (int j = 0; j < N; ++j)
		{
			string inpMBTI;
			cin >> inpMBTI;

			MBTI_container.push_back(inpMBTI);
		}

		if (N > 32)
		{
			cout << 0 << '\n';
			continue;
		}
		// Calculate
		int result = FindResult(MBTI_container);

		cout << result << '\n';
	}


	return 0;
}
