#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 승수 계산
int pow(int count, int num)
{
	int result = 1;
	while (count > 0)
	{
		result *= num;
		count--;
	}
	return result;
}

// 문자열 -> 숫자변환
int StrToInt(string& str)
{
	int result = 0;

	int len = str.length();
	int powCount = 0;
	for (int i = len - 1; i > -1; --i)
	{
		result += (str[i] - '0') * pow(powCount, 10);
		powCount++;
	}
	return result;
}

int Calculate(string& inpStr)
{
	// 연산자를 담는 배열
	// 숫자를 담는 배열 구분지어줌.
	int result = 0;

	string num1 = "";
	vector<char> operatorBox;
	vector<int> numberBox;
	int minusCount = 0;

	for (int i = 0; i < inpStr.length(); ++i)
	{
		if (inpStr[i] - '0' >= 0 && inpStr[i] - '0' < 10)
			num1 += inpStr[i];
		else
		{
			if (inpStr[i] == '-')
			{
				minusCount++;
			}

			numberBox.push_back(StrToInt(num1));
			operatorBox.push_back(inpStr[i]);

			num1 = "";
		}

		// 마지막 숫자인경우
		if (i == inpStr.length() - 1)
		{
			numberBox.push_back(StrToInt(num1));
		}
	}

	// Final Calculate
	// 
	// Case 1) '-' 연산이 없는경우 => 주어진 숫자들을 모두 합한 결과를 반환
	// Case 2) '-' 연산이 있는경우
	// 1) '-' 연산만 존재하는 경우 => 처음 숫자를 제외하고 모두 뺀 값을 반환.
	// 2) 그 외 : 각 배열 마지막 인덱스 값을 꺼내줌.
	// => 연산수행 '+' 연산자를 만난경우, 임시로 합산한 후, '-' 연산자를 만났을 때, 마지막에 임시합산값을 결과값에서 빼줌.

	int tempSum = 0;
	int indexOperator = operatorBox.size() - 1;
	for (int i = numberBox.size() - 1; i > -1; --i)
	{
		char charOperator = '+';
		if (indexOperator > -1)
		{
			charOperator = operatorBox[indexOperator];
			indexOperator--;
		}

		if (charOperator == '+')
		{
			if (minusCount > 0)
				tempSum += numberBox[i];
			else
				result += numberBox[i];
		}
		else // charOperator == '-'
		{
			if (minusCount > 0)
				minusCount--;

			if (tempSum == 0)
				result -= numberBox[i];
			else
			{
				result -= tempSum;
				result -= numberBox[i];
				tempSum = 0;
			}
		}
	}
	result -= tempSum;

	return result;
}

int main()
{
	string inpStr;
	cin >> inpStr;

	int result = Calculate(inpStr);
	cout << result << '\n';

	return 0;
}