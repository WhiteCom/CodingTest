#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string buffer; // 버퍼제거
		getline(cin, buffer);
		string inputSound;
		getline(cin, inputSound);
		
		map<string, bool> soundData;
		while (true)
		{
			string a, b, c;
			cin >> a >> b >> c;
			if (a == "what")
			{
				cin >> b >> c; // input : fox say?
				break;
			}
			soundData[c] = true;
		}

		string temp = "";
		for (int i = 0; i < inputSound.size(); ++i)
		{
			if (inputSound[i] == ' ')
			{
				if (!soundData[temp])
					cout << temp << " ";
				temp = "";
				continue;
			}
			temp += inputSound[i];
		}
		if (!soundData[temp])
			cout << temp << " \n";
	}
	return 0;
}