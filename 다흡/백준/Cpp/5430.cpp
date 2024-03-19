#include <iostream>
#include <deque>
#include <string>

using namespace std;

/*
아래 경우 고려해서 구현필요
(Case 1)
input)
1
D
1
[1]

output)
[]

(Case 2)
input)
1
R
1
[12]

output)
[12]
*/

void PrintAfterCommand(deque<int>& arr, bool canDelete)
{
	if (canDelete == false)
	{
		cout << "error\n";
		return;
	}

	// Convert 
	string resultStr = "[";

	for (int i = 0; i < arr.size(); ++i)
	{
		resultStr += to_string(arr[i]);

		if (i == arr.size() - 1)
			break;
		resultStr += ",";
	}
	resultStr += "]";

	// Print Result
	cout << resultStr << '\n';
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		// Input
		string command;
		int arrLength;
		string arrContents;
		cin >> command >> arrLength >> arrContents;
		
		deque<int> arr;
		string tempNumber = "";
		for (int i = 0; i < arrContents.length(); ++i)
		{
			if (arrContents[i] == '[' || arrContents[i] == ']')
				continue;

			// 숫자인 경우
			if (0 <= arrContents[i] - '0' && arrContents[i] - '0' < 10)
				tempNumber.push_back(arrContents[i]);
			else if(arrContents[i] == ',')
			{
				arr.push_back(stoi(tempNumber));
				tempNumber = "";
			}
		}
		if (tempNumber.length() > 0)
		{
			int num = stoi(tempNumber);
			arr.push_back(stoi(tempNumber));
		}

		// PreProcess
		int ReverseCount = 0;
		int DeleteCount = 0;
		for (int i = 0; i < command.length(); ++i)
		{
			if (command[i] == 'R')
				ReverseCount++;
			else if (command[i] == 'D')
				DeleteCount++;
		}

		bool IsReverse = false;
		bool canDelete = true;
		// Command Process
		for (int i = 0; i < command.length(); ++i)
		{
			if (command[i] == 'R')
				IsReverse = !IsReverse;

			else if (command[i] == 'D')
			{
				if (arr.size() > 0)
					canDelete = true;
				else
					canDelete = false;

				if (IsReverse == true && arr.size() > 0)
					arr.pop_back();
				else if (IsReverse == false && arr.size() > 0)
					arr.pop_front();
			}
		}

		// Result arr
		deque<int> result;
		if (IsReverse == true)
		{
			for (int i = arr.size() - 1; i > -1; --i)
				result.push_back(arr[i]);
		}
		else // if(IsReverse == false)
		{
			for (int i = 0; i < arr.size(); ++i)
				result.push_back(arr[i]);
		}

		// Print Result
 		PrintAfterCommand(result, canDelete);
	}
	return 0;
}