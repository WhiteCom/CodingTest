#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �¼� ���
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

// ���ڿ� -> ���ں�ȯ
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
	// �����ڸ� ��� �迭
	// ���ڸ� ��� �迭 ����������.
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

		// ������ �����ΰ��
		if (i == inpStr.length() - 1)
		{
			numberBox.push_back(StrToInt(num1));
		}
	}

	// Final Calculate
	// 
	// Case 1) '-' ������ ���°�� => �־��� ���ڵ��� ��� ���� ����� ��ȯ
	// Case 2) '-' ������ �ִ°��
	// 1) '-' ���길 �����ϴ� ��� => ó�� ���ڸ� �����ϰ� ��� �� ���� ��ȯ.
	// 2) �� �� : �� �迭 ������ �ε��� ���� ������.
	// => ������� '+' �����ڸ� �������, �ӽ÷� �ջ��� ��, '-' �����ڸ� ������ ��, �������� �ӽ��ջ갪�� ��������� ����.

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