#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int stringSetNumber, inputNumber;
	cin >> stringSetNumber >> inputNumber;

	// key-value binary search tree
	// key : word
	// value : exist or not
	map<string, bool> data;

	// input string set
	for (int i = 0; i < stringSetNumber; ++i)
	{
		string inp;
		cin >> inp;
		data[inp] = true;
	}

	int count = 0;
	// input test case
	for (int i = 0; i < inputNumber; ++i)
	{
		string target;
		cin >> target;
	
		// find target string in string set
		if (data.find(target) != data.end())
			count++;
	}

	cout << count << '\n';
	return 0;
}