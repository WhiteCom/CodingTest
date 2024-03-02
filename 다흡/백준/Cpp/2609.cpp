#include <iostream>

using namespace std;

int GCD(int num1, int num2)
{
	int result = 0;

	int minNum = num1 < num2 ? num1 : num2;
	for (int i = 1; i <= minNum; ++i)
	{
		if (num1 % i == 0 && num2 % i == 0)
			result = i;
	}

	return result;
}

int LCM(int num1, int num2)
{
	int result = 0;

	int gcdNum = GCD(num1, num2);
	
	int temp1 = num1 / gcdNum;
	int temp2 = num2 / gcdNum;

	result = gcdNum * temp1 * temp2;

	return result;
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	cout << GCD(num1, num2) << '\n' << LCM(num1, num2) << '\n';

	return 0;
}