#include <iostream>
#include <vector>
#include <string>

using namespace std;

void CheckLuck(vector<int>& alphaArray, int inputLength, int& result)
{
	for (int i = 0; i < inputLength - 1; ++i)
	{
		if (alphaArray[i] == alphaArray[i + 1])
			return;
	}

	result++;
}

void DFS(vector<int>& alphaArray, vector<int>& inArr, vector<int>& check, int inputLength, int count, int& result)
{
	if (count == inputLength)
	{
		CheckLuck(alphaArray, inputLength, result);
		return;
	}

	for (int i = 0; i < inputLength; ++i)
	{
		if (check[i])
			continue;
		alphaArray[count] = inArr[i];
		check[i] = 1;
		DFS(alphaArray, inArr, check, inputLength, count + 1, result);
		check[i] = 0;
	}
}

int main()
{
	string inputStr;
	cin >> inputStr;

	int inputLength = inputStr.length();
	vector<int> alphaArray(11, 0);
	vector<int> inArr(11, 0);
	vector<int> check(11, 0);
	vector<int> duplicateAlphabet(26, 0); // 중복되는 알파벳 갯수

	int duplicateNum = 1;
	int result = 0;

	// Input to array
	for (int i = 0; i < inputLength; ++i)
	{
		inArr[i] = inputStr[i] - 'a';
	}

	// 한 글자씩 추가해 전부 확인
	for (int i = 0; i < inputLength; ++i)
	{
		alphaArray[0] = inArr[i];
		check[i] = 1;
		DFS(alphaArray, inArr, check, inputLength, 1, result);
		check[i] = 0;
	}

	// 중복되는 알파벳 있는 경우 각각 몇 변 나오는지 체크
	for (int i = 0; i < inputLength; ++i)
		duplicateAlphabet[inArr[i]]++;

	// 중복제거를 위해 나눠줄 값 연산
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 2; j <= duplicateAlphabet[i]; ++j)
			duplicateNum *= j;
	}

	cout << result / duplicateNum;

	return 0;
}