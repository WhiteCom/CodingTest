#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Compare
{
	bool operator() (const string& s1, const string& s2) const
	{
		if (s1.length() == s2.length())
			return s1 < s2;
		else
			return s1.length() < s2.length();
	}
};

int main()
{
	int N;
	cin >> N;

	set<string, Compare> wordData;
	string temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		wordData.insert(temp);
	}

	set<string>::iterator it;
	for (it = wordData.begin(); it != wordData.end(); ++it)
		cout << it->c_str() << '\n';

	return 0;
}