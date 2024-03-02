#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;


	if (a % b == 0)
	{
		cout << a / b << '\n';
		return 0;
	}
	
	string result = "";

	int quotient = a / b;
	int remainder = a % b;
	
	result += to_string(quotient);

	if (remainder == 0)
	{
		cout << result << '\n';
		return 0;
	}

	result += ".";

	int count = 15;
	while (remainder != 0 && count > 0)
	{
		remainder *= 10;
		quotient = remainder / b;
		remainder = remainder % b;
		result += to_string(quotient);
		count--;
	}
	
	cout << result << '\n';

	return 0;
}