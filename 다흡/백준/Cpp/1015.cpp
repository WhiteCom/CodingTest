#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// P[0], P[1], ... , P[N-1] = 0 ~ N-1 까지 (포함) 수를 한번씩 포함하고 있는 수열
// 수열 P 를 길이가 N 인 배열 A에 적용하면 길이가 N인 배열 B가 된다. 
// B[ P[i] ] = A[i]
// 비 내림차순 : 각각의 원소가 바로 앞에 있는 원소보다 크거나 같을 경우를 말한다. 
// 만약 그런 수열이 여러개라면 사전순 오름차순으로 출력한다. 

struct sData
{
	int index;
	int value;
};

bool compare(sData s1, sData s2)
{
	if (s1.value == s2.value)
		return s1.index < s2.index;

	return s1.value < s2.value;
}

void Result_Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << '\n';
}

int main()
{
	int N;
	cin >> N;
	vector<sData> A_arr(N, {0, 0});
	for (int i = 0; i < N; ++i)
	{
		A_arr[i].index = i;
		cin >> A_arr[i].value;
	}

	sort(A_arr.begin(), A_arr.end(), compare);

	// P 수열 만들기
	// A 수열의 각 원소값이 P 수열의 인덱스번호
	// 단, A 수열의 원소값이 동일한게 여럿있는경우, A 수열의 인덱스값으로 번호 매기기

	int P_index = 0;
	vector<int> P_arr(N, 0);
	for (int i = 0; i < A_arr.size(); ++i)
	{
		P_arr[A_arr[i].index] = P_index;
		P_index++;
	}

	// Result
	Result_Print(P_arr);
	
	return 0;
}