#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	map<string, int> data_A;
	map<string, int> data_B;

	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		data_A[name] = 1;
	}

	for (int i = 0; i < M; ++i)
	{
		string name;
		cin >> name;
		data_B[name] = 1;
	}

	map<string, int> compare;

	// Calculate
	map<string, int>::iterator it;
	for (it = data_A.begin(); it != data_A.end(); ++it)
	{
		if (data_B.find(it->first) != data_B.end())
			compare[it->first] = 1;
	}

	// Result
	cout << compare.size() << '\n';
	for (it = compare.begin(); it != compare.end(); ++it)
	{
		cout << it->first << '\n';
	}

	return 0;
}