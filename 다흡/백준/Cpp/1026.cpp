#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
S = A[0] * B[0] + A[1] * B[1] + ... + A[N-1] * B[N-1]
A를 정렬해서 S 가 최소값이 되도록 하자.
*/

int main()
{
	int N;
	cin >> N;

	vector<int> numbers_A(N, 0);
	vector<int> numbers_B(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> numbers_A[i];

	for (int i = 0; i < N; ++i)
		cin >> numbers_B[i];

	sort(numbers_A.begin(), numbers_A.end());
	sort(numbers_B.begin(), numbers_B.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		result += numbers_A[i] * numbers_B[i];
	}

	cout << result << '\n';

	return 0;
}