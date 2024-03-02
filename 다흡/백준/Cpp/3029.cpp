#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inp_curTime;
	string inp_waitTime;
	cin >> inp_curTime;
	cin >> inp_waitTime;

	int curHH, curMM, curSS;
	int waitHH, waitMM, waitSS;

	curHH = stoi(inp_curTime.substr(0, 2));
	curMM = stoi(inp_curTime.substr(3, 2));
	curSS = stoi(inp_curTime.substr(6, 2));

	waitHH = stoi(inp_waitTime.substr(0, 2));
	waitMM = stoi(inp_waitTime.substr(3, 2));
	waitSS = stoi(inp_waitTime.substr(6, 2));

	if (curHH == waitHH && curMM == waitMM && curSS == waitSS)
	{
		cout << "24:00:00\n";
		return 0;
	}

	// Test
	bool greaterSS = false;
	bool greaterMM = false;

	if (waitSS < curSS)
	{
		waitMM--;
		waitSS += 60;
	}

	if (waitMM < curMM)
	{
		waitHH--;
		waitMM += 60;
	}

	if (waitHH < curHH)
	{
		waitHH += 24;
	}

	int resultHH, resultMM, resultSS;
	resultHH = waitHH - curHH;
	resultMM = waitMM - curMM;
	resultSS = waitSS - curSS;
	
	string str_resultHH = resultHH < 10 ? ("0" + to_string(resultHH)) : (to_string(resultHH));
	string str_resultMM = resultMM < 10 ? ("0" + to_string(resultMM)) : (to_string(resultMM));
	string str_resultSS = resultSS < 10 ? ("0" + to_string(resultSS)) : (to_string(resultSS));

	string result = str_resultHH + ":" + str_resultMM + ":" + str_resultSS;
	cout << result << '\n';

	return 0;
}