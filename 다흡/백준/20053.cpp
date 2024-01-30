#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		int n;
		cin >> n;
		
		int minNum = 1000000, maxNum = -1000000;
		for (int j = 0; j < n; ++j)
		{
			int tempNum;
			cin >> tempNum;
			minNum = tempNum < minNum ? tempNum : minNum;
			maxNum = tempNum > maxNum ? tempNum : maxNum;
		}

		cout << minNum << " " << maxNum << '\n';
	}
	return 0;
}