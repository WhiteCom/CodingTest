#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int beautifulPairs(vector<int>& A, vector<int>& B)
{
	int result = 0;

	vector<int> tempA = A;
	vector<int> tempB = B;

	sort(tempA.begin(), tempA.end());
	sort(tempB.begin(), tempB.end());

	int idx_A = 0;
	int idx_B = 0;

	while (idx_A < tempA.size() && idx_B < tempB.size())
	{
		if (tempA[idx_A] < tempB[idx_B])
		{
			idx_A++;
			continue;
		}

		if (tempA[idx_A] > tempB[idx_B])
		{
			idx_B++;
			continue;
		}

		if (tempA[idx_A] == tempB[idx_B])
			result++;

		idx_A++;
		idx_B++;
	}

	return result < A.size() ? result + 1 : result - 1;
}

int main()
{
	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<int> B(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	for (int i = 0; i < N; ++i)
		cin >> B[i];

	int result = beautifulPairs(A, B);
	cout << result << '\n';

	return 0;
}