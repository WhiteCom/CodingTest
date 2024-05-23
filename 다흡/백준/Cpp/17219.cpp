#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

pair<string, string> SplitString(string line)
{
	pair<string, string> result;

	string str = "";
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] != ' ')
			str += line[i];
		else
		{
			result.first = str;
			str = "";
		}
	}
	result.second = str;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int urlCount, findCount;
	cin >> urlCount >> findCount;

	map<string, string> data;

	cin.ignore();
	for (int i = 0; i < urlCount; ++i)
	{
		string line;
		getline(cin, line);

		pair<string, string> splitStr = SplitString(line);
		string key = splitStr.first;
		string value = splitStr.second;

		data[key] = value;
	}

	for (int i = 0; i < findCount; ++i)
	{
		string query;
		cin >> query;

		cout << data[query] << '\n';
	}

	return 0;
}
