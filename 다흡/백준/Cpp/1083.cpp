#include <iostream>
#include <vector>

#define min(num1, num2) (num1) < (num2) ? (num1) : (num2)

using namespace std;

/*
* 해결전략
1. 그리디하게 앞자리부터 큰 수로 만들어야 한다.
2. i 번째 자리에서 X칸 떨어져 있는 수는 X번 스왑으로 i번째 자리로 끌얼올 수 있다.
3. S번 이내에 스왑으로 끌어올 수 있는 가장 큰 수를 앞으로 끌어오기를 반복한다.
*/

int main()
{
	int N;
	cin >> N;
	
	vector<int> arr(N + 1, 0);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int S;
	cin >> S;

	int start = 0;
	while (start < N && S > 0)
	{
		// S번 이내의 스왑으로 끌어올 수 있는 가장 큰 값을 arr[start]로 끌어오기
		int maxIdx = start;
		int minNum = min(N - 1, start + S);
		int i = 0;
		for (i = start; i <= minNum; ++i)
		{
			if (arr[maxIdx] < arr[i])
				maxIdx = i;

			minNum = min(N - 1, start + S);
		}
		for (i = maxIdx; i > start; --i)
		{
			// Swap
			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;

			S--;
		}

		start++;
	}

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";

	return 0;
}