#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> strTimeToIntTime(string& strTime)
{
	// three element HH MM SS
	vector<int> intTime(3, 0);

	int HH, MM, SS;
	HH = stoi(strTime.substr(0, 2));
	MM = stoi(strTime.substr(3, 2));
	SS = stoi(strTime.substr(6, 2));

	intTime[0] = HH;
	intTime[1] = MM;
	intTime[2] = SS;

	return intTime;
}

string CalculateTimeDifference(vector<int>& curTime, vector<int>& waitTime)
{
	// case same time, wait 24 Hours
	if (curTime[0] == waitTime[0]
		&& curTime[1] == waitTime[1]
		&& curTime[2] == waitTime[2])
		return "24:00:00";

	int diffSS=0, diffMM=0, diffHH=0;

	// compare seconds
	if (waitTime[2] < curTime[2])
	{
		diffSS += 60;
		diffMM -= 1;

	}
	diffSS += waitTime[2] - curTime[2];

	// compare minutes
	if (waitTime[1] < curTime[1])
	{
		diffMM += 60;
		diffHH -= 1;

	}
	diffMM += waitTime[1] - curTime[1];

	// compare hours
	if (waitTime[0] < curTime[0])
	{
		diffHH += 24;
	}
	diffHH += waitTime[0] - curTime[0];

	// case negative result
	if (diffSS < 0)
	{
		diffSS += 60;
		diffMM--;
	}
	if (diffMM < 0)
	{
		diffMM += 60;
		diffHH--;
	}
	if (diffHH < 0)
		diffHH += 24;

	string strHH, strMM, strSS;
	strHH = diffHH < 10 ? ("0" + to_string(diffHH)) : (to_string(diffHH));
	strMM = diffMM < 10 ? ("0" + to_string(diffMM)) : (to_string(diffMM));
	strSS = diffSS < 10 ? ("0" + to_string(diffSS)) : (to_string(diffSS));
		 
	string result = strHH + ":" + strMM + ":" + strSS;

	return result;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> s1Time = strTimeToIntTime(s1);
	vector<int> s2Time = strTimeToIntTime(s2);

	string result = CalculateTimeDifference(s1Time, s2Time);
	cout << result << '\n';
	
	return 0;
}