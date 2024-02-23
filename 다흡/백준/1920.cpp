#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, M;
	map<int, bool> inputData;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int tempNum;
		cin >> tempNum;
		inputData[tempNum] = true;
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int tempNum;
		cin >> tempNum;
		if (inputData.find(tempNum) != inputData.end())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}