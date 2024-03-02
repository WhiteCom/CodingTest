#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// add ( Big Integer + Big Integer )
string add(string& a, string& b)
{
	int t = 0;
	int length = a.length() > b.length() ? a.length() : b.length();

	string result;
	for (int i = 0; i < length; ++i)
	{
		if (i < a.length())
		{
			t += (a[i] - '0');
		}
		if (i < b.length())
		{
			t += (b[i] - '0');
		}
		 
		result.push_back(t % 10 + '0');
		t /= 10;
	}
	if (t > 0)
		result.push_back(t % 10 + '0');

	return result;
}

int main()
{
	int x;

	string inp1, inp2;
	cin >> inp1 >> inp2;
	
	string result;
	reverse(inp1.begin(), inp1.end());
	reverse(inp2.begin(), inp2.end());
	
	result = add(inp1, inp2);
	
	reverse(result.begin(), result.end());
	cout << result;
	
	
	return 0;
}