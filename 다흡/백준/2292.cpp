#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;


	if (num == 1)
	{
		cout << "1\n";
		return 0;
	}

	int sum = 1;
	int range = 1;
	while (true)
	{
		sum += range * 6 - 6;
		if (sum >= num)
			break;
		range++;
	}

	cout << range;

	return 0;
}