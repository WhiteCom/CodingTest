#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string N;
	cin >> N;

	vector<string> movieData(10000, "");

	int numCount = 0;
	for (int num = 0; numCount < 10000; num++)
	{
		string temp = to_string(num);
		if (temp.find("666") != string::npos)
		{
			movieData[numCount] = temp;
			numCount++;
		}
	}

	cout << stoi(movieData[stoi(N) - 1]) << '\n';

	return 0;
}