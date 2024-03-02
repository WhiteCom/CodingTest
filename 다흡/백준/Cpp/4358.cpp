#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> tree_data;
	int totalNum = 0;

	// input
	string input;
	while (getline(cin, input))
	{
		tree_data[input]++;
		totalNum++;
	}

	map<string, int>::iterator it;
	
	// 소수점 4자리
	cout << fixed;
	cout.precision(4);
	for (it = tree_data.begin(); it != tree_data.end(); ++it)
	{
		float num = static_cast<float>(it->second) / totalNum * 100;
		cout << it->first << " " << num << '\n';
	}

	return 0;
}