#include <iostream>
#include <string>
#include <cstring> // memset

using namespace std;

//////////////////////////////////////////////////////////////////////
// Problem URL : https://www.acmicpc.net/problem/10808
//////////////////////////////////////////////////////////////////////
int main()
{
	string input;
	cin >> input;

	int alphabet[26];
	memset(alphabet, 0x00, sizeof(int) * 26);

	for (int i = 0; i < input.length(); ++i)
	{
		switch (input[i] - 'a')
		{
		case 0:		alphabet[0] += 1; break;
		case 1:		alphabet[1] += 1; break;
		case 2:		alphabet[2] += 1; break;
		case 3:		alphabet[3] += 1; break;
		case 4:		alphabet[4] += 1; break;
		case 5:		alphabet[5] += 1; break;
		case 6:		alphabet[6] += 1; break;
		case 7:		alphabet[7] += 1; break;
		case 8:		alphabet[8] += 1; break;
		case 9:		alphabet[9] += 1; break;
		case 10:	alphabet[10] += 1; break;
		case 11:	alphabet[11] += 1; break;
		case 12:	alphabet[12] += 1; break;
		case 13:	alphabet[13] += 1; break;
		case 14:	alphabet[14] += 1; break;
		case 15:	alphabet[15] += 1; break;
		case 16:	alphabet[16] += 1; break;
		case 17:	alphabet[17] += 1; break;
		case 18:	alphabet[18] += 1; break;
		case 19:	alphabet[19] += 1; break;
		case 20:	alphabet[20] += 1; break;
		case 21:	alphabet[21] += 1; break;
		case 22:	alphabet[22] += 1; break;
		case 23:	alphabet[23] += 1; break;
		case 24:	alphabet[24] += 1; break;
		case 25:	alphabet[25] += 1; break;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << alphabet[i] << " ";
	}
	cout << '\n';
	return 0;
}