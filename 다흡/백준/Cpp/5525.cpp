#include <iostream>
#include <vector>
#include <string>

using namespace std;


string CreateCustomString(int N)
{
	string result = "";

	int count = 0;
	int i = 0;
	while (true)
	{
		if(i % 2 == 0)
			result += 'I';
		else if (i % 2 == 1)
		{
			result += 'O';
			count++;
		}

		// End loop
		if (count == N)
		{
			result += 'I';
			break;
		}

		++i;
	}

	return result;
}

// 무식한 방법, 완전탐색
// 모든 문자열 비교 O(N * M) => 비효율적
int BruteForceSearch(string& inpStr, string& targetStr)
{
	int resultCount = 0;
	int targetStrLength = targetStr.length();
	for (int i = 0; i < inpStr.length(); ++i)
	{
		if (inpStr[i] == 'I')
		{
			string subString = inpStr.substr(i, targetStrLength); // "IOIOI..."
			if (subString == targetStr)
				resultCount++;
		}
	}

	return resultCount;
}

// 탐색 문자열의 접두, 접미사의 길이를 구해주는 함수
vector<int> GetPartialMatch(string& srcString)
{
	int srcLength = srcString.length();
	vector<int> result(srcLength, 0);

	// 아래는 2중반복문이라, 비효율, 따라서 이 함순내에서 KMP 알고리즘을 다시 적용
/*

	// 탐색 문자열의 처음부터 끝까지 모두 비교하여 접두, 접미사의 길이를 계산한다.
	for (int begin = 1; begin < srcLength; ++begin)
	{
		for (int i = 0; i < begin + i < srcLength; ++i)
		{
			if (srcString[begin + i] != srcString[i])
				break;

			result[begin + i] = result[begin + i] > (i + 1) ? result[begin + i] : (i + 1);
		}
	}

	return result;
*/

	// 여기서 부터 KMP 를 이용해 접두, 접미사 길이 구하기
	int begin = 1, matched = 0;

	while (begin + matched < srcLength)
	{
		// 탐색 문자열과 탐색 문자열 자신을 매칭시킴
		if (srcString[begin + matched] == srcString[matched])
		{
			matched++;
			result[begin + matched - 1] = matched; // 매칭을 진행하면서, 접두 접미사 배열을 바로 갱신
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				// KMP 문자열 탐색 알고리즘과 동일하게 불일치 발생 시
				// 매칭을 진행하면서 기존에 구했던 접두 접미사 길이 만큼 탐색을 건너뛸 수 있다.
				begin += matched - result[matched - 1];
				matched = result[matched - 1];
			}
		}
	}

	return result;
}

// KMP 문자열 비교 알고리즘
// N : 원본 문자열, M : 비교 문자열
// O(N + M) 
vector<int> KMPSearch(string& srcString, string& targetString)
{
	int srcLength = srcString.length();
	int targetLength = targetString.length();
	
	vector<int> result;

	// 탐색할 문자열의 접두사, 접미사 길이를 문자열의 처음부터 끝까지 미리 계산
	vector<int> pi = GetPartialMatch(targetString);
	int begin = 0, matched = 0;

	while (begin <= srcLength - targetLength)
	{
		// 탐색할 문자열과 원본 문자열에서 현재 위치의 문자가 동일한 경우
		if (matched < targetLength && srcString[begin + matched] == targetString[matched])
		{
			// 일치하는 경우 matched 가 1증가
			++matched;

			// 문자열이 모두 일치하는 경우
			if (matched == targetLength)
				result.push_back(begin);
		}
		else
		{
			// 일치하는 부분이 없는 경우, 다음 위치의 문자부터 탐색
			if (matched == 0)
			{
				++begin;
			}
			// 문자열이 불일치 하므로, 접두사, 접미사의 길이만큼 건너뜀.
			else
			{
				// 현재 불일치가 발생한 위치는 begin + matched
				// 여기서 접두, 접미사의 길이인 pi[matched - 1]을 빼주면 다음 탐색 시작 위치
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}


	return result;
}

int main()
{
	int N;
	int stringLength;
	string inpStr;
	cin >> N >> stringLength >> inpStr;

	string targetStr = CreateCustomString(N);

	
	int resultCount = 0;
	//resultCount = BruteForceSearch(inpStr, targetStr);
	
	vector<int> KMP_Result = KMPSearch(inpStr, targetStr);

	resultCount = KMP_Result.size();

	cout << resultCount << '\n';

	return 0;
}