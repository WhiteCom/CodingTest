#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num;
	while (true)
	{
		cin >> num;
		if (num == "0")
			break;

		bool flag = true;
		for (int i = 0; i < num.length() / 2; ++i)
		{
			if (num[i] != num[num.length() - 1 - i])
			{
				flag = false;
				break;
			}
		}

		if (flag) cout << "yes\n";
		else cout << "no\n";

	}
	return 0;
}