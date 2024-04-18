#include <iostream>
#include <vector>
#include <string>

#define MAX_VALUE 50

using namespace std;

/*
브루트포스 + 비둘기집 원리 알고리즘 이용

* 비둘기집 원리
- N 개의 비둘기 집에 N+1 비둘기가 있다면, 무조건 2마리 이상인 집이 존재한다.
- MBTI가 16가지 있을때 17명이 존재한다면, 무조건 2명은 MBTI 가 겹친다.
- 따라서 N > 32 인 경우, MBTI가 동일한 사람인 3명 존재한다. (이때는 이 동일한 사람들을 선택하게 되고, 최소 심리적 거리 0이 됨)
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

		// 비둘기집 원리에 따라 아래와 같이 분류됨
		// 1. N > 2 * MBTI_COUNT : 동일 MBTI 3명 존재
		// 2. N > 1 * MBTI_COUNT : 동일 MBTI 2명 존재 => 이 로직은 구현 못해봄
		// 3. 그 외는 서로 다른 MBTI 가질 수 있음.

		// 1. MBTI 동일한 사람 3명이상이 무조건 나오는 경우

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
