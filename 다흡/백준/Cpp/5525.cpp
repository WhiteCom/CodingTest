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

// ������ ���, ����Ž��
// ��� ���ڿ� �� O(N * M) => ��ȿ����
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

// Ž�� ���ڿ��� ����, ���̻��� ���̸� �����ִ� �Լ�
vector<int> GetPartialMatch(string& srcString)
{
	int srcLength = srcString.length();
	vector<int> result(srcLength, 0);

	// �Ʒ��� 2�߹ݺ����̶�, ��ȿ��, ���� �� �Լ������� KMP �˰����� �ٽ� ����
/*

	// Ž�� ���ڿ��� ó������ ������ ��� ���Ͽ� ����, ���̻��� ���̸� ����Ѵ�.
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

	// ���⼭ ���� KMP �� �̿��� ����, ���̻� ���� ���ϱ�
	int begin = 1, matched = 0;

	while (begin + matched < srcLength)
	{
		// Ž�� ���ڿ��� Ž�� ���ڿ� �ڽ��� ��Ī��Ŵ
		if (srcString[begin + matched] == srcString[matched])
		{
			matched++;
			result[begin + matched - 1] = matched; // ��Ī�� �����ϸ鼭, ���� ���̻� �迭�� �ٷ� ����
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				// KMP ���ڿ� Ž�� �˰���� �����ϰ� ����ġ �߻� ��
				// ��Ī�� �����ϸ鼭 ������ ���ߴ� ���� ���̻� ���� ��ŭ Ž���� �ǳʶ� �� �ִ�.
				begin += matched - result[matched - 1];
				matched = result[matched - 1];
			}
		}
	}

	return result;
}

// KMP ���ڿ� �� �˰���
// N : ���� ���ڿ�, M : �� ���ڿ�
// O(N + M) 
vector<int> KMPSearch(string& srcString, string& targetString)
{
	int srcLength = srcString.length();
	int targetLength = targetString.length();
	
	vector<int> result;

	// Ž���� ���ڿ��� ���λ�, ���̻� ���̸� ���ڿ��� ó������ ������ �̸� ���
	vector<int> pi = GetPartialMatch(targetString);
	int begin = 0, matched = 0;

	while (begin <= srcLength - targetLength)
	{
		// Ž���� ���ڿ��� ���� ���ڿ����� ���� ��ġ�� ���ڰ� ������ ���
		if (matched < targetLength && srcString[begin + matched] == targetString[matched])
		{
			// ��ġ�ϴ� ��� matched �� 1����
			++matched;

			// ���ڿ��� ��� ��ġ�ϴ� ���
			if (matched == targetLength)
				result.push_back(begin);
		}
		else
		{
			// ��ġ�ϴ� �κ��� ���� ���, ���� ��ġ�� ���ں��� Ž��
			if (matched == 0)
			{
				++begin;
			}
			// ���ڿ��� ����ġ �ϹǷ�, ���λ�, ���̻��� ���̸�ŭ �ǳʶ�.
			else
			{
				// ���� ����ġ�� �߻��� ��ġ�� begin + matched
				// ���⼭ ����, ���̻��� ������ pi[matched - 1]�� ���ָ� ���� Ž�� ���� ��ġ
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