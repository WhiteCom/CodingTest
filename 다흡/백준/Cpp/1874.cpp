#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	stack<int> s;
	vector<char> result;
	int tempNum = 1;

	for (int i = 0; i < N; ++i)
	{
		int inputNum = 0;
		cin >> inputNum;

		if (s.empty())
		{
			for (tempNum; tempNum <= inputNum; ++tempNum)
			{
				s.push(tempNum);
				result.push_back('+');
			}
		}

		while (!s.empty())
		{
			if (s.top() == inputNum)
			{
				s.pop();
				result.push_back('-');
				break;
			}
			else if (s.top() < inputNum)
			{
				for (tempNum; tempNum <= inputNum; ++tempNum)
				{
					s.push(tempNum);
					result.push_back('+');
				}
			}
			else if(s.top() > inputNum)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << '\n';
	
	return 0;
}