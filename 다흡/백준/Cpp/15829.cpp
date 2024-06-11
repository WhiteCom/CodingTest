#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int length;
	char inputStr[101];
	cin >> length >> inputStr;

	long long int hash = 0;

	long long int result = 1;
	for (int i = 0; i < length; ++i)
	{
		// a ~ z => 1 ~ 26
		char ch = inputStr[i];
		hash = (hash + (ch - 96) * result) % 1234567891;

		result = (result * 31) % 1234567891;
	}

	cout << hash << '\n';

	return 0;
}