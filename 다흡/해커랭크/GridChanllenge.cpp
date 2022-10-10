#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
* Complete the 'gridChallenge' function below.
*
* The function is expected to return a STRING.
* The function accepts STRING_ARRAY grid as parameter.
*/

string gridChallenge(vector<string> grid) {
	int grid_len = grid.size();

	// sort in grid strings
	for (int i = 0; i < grid_len; ++i)
	{
		sort(grid[i].begin(), grid[i].end());
	}

	for (int i = 0; i < grid_len - 1; ++i)
	{
		string s1 = grid[i];
		string s2 = grid[i + 1];

		for (int j = 0; j < s1.length(); ++j)
		{
			if (s1[j] > s2[j])
				return "NO";
		}
	}

	return "YES";
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string t_temp;
	getline(cin, t_temp);

	int t = stoi(ltrim(rtrim(t_temp)));

	for (int t_itr = 0; t_itr < t; t_itr++) {
		string n_temp;
		getline(cin, n_temp);

		int n = stoi(ltrim(rtrim(n_temp)));

		vector<string> grid(n);

		for (int i = 0; i < n; i++) {
			string grid_item;
			getline(cin, grid_item);

			grid[i] = grid_item;
		}

		string result = gridChallenge(grid);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
