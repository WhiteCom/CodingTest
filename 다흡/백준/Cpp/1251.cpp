#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string inputStr;
	cin >> inputStr;

	vector<string> result_container;

	int firstIdx = 0, secondIdx = 1, thirdIdx = 2;
	for (int firstIdx = 0; firstIdx < inputStr.length() - 2; ++firstIdx)
	{
		for (int secondIdx = firstIdx + 1; secondIdx < inputStr.length() - 1; ++secondIdx)
		{
			for (int thirdIdx = secondIdx + 1; thirdIdx < inputStr.length(); ++thirdIdx)
			{
				// Divide three words
				string firstStr = inputStr.substr(0, secondIdx - firstIdx);
				string secondStr = inputStr.substr(secondIdx, thirdIdx - secondIdx);
				string thirdStr = inputStr.substr(thirdIdx);

				// Reverse
				reverse(firstStr.begin(), firstStr.end());
				reverse(secondStr.begin(), secondStr.end());
				reverse(thirdStr.begin(), thirdStr.end());

				// Combine
				string temp_result = firstStr + secondStr + thirdStr;
				if(temp_result.length() == inputStr.length())
					result_container.push_back(temp_result);
			}
		}
	}

	sort(result_container.begin(), result_container.end());

	cout << result_container[0] << '\n';

	return 0;
}