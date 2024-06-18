#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define MAX_VALUE (INT_MAX)

using namespace std;

bool Check(int* target_alpha, int* temp_alpha)
{
	for (int i = 0; i < 26; ++i)
	{
		if (target_alpha[i] > temp_alpha[i])
			return false;
	}
	return true;
}

void Combination(vector< pair<int, string>>& vec_data, int* target_alpha, int* temp_alpha, int bookIdx, int priceSum, int maxCount, int& result)
{
	if (bookIdx >= maxCount)
	{
		if (Check(target_alpha, temp_alpha))
			result = result > priceSum ? priceSum : result;

		return;
	}

	string temp = vec_data[bookIdx].second;

	for (char ch : temp)
		temp_alpha[ch - 'A']++;

	Combination(vec_data, target_alpha, temp_alpha, bookIdx + 1, priceSum + vec_data[bookIdx].first, maxCount, result);

	for (char ch : temp)
		temp_alpha[ch - 'A']--;

	Combination(vec_data, target_alpha, temp_alpha, bookIdx + 1, priceSum, maxCount, result);
}

int main()
{
	string targetStr;
	cin >> targetStr;

	int target_alpha[26] = { 0, };
	int temp_alpha[26] = { 0, };
	for (int i = 0; i < targetStr.length(); ++i)
	{
		target_alpha[targetStr[i] - 'A']++;
	}

	int bookCount;
	cin >> bookCount;

	vector< pair< int, string>> vec_data(bookCount, {0, ""});
	for (int i = 0; i < bookCount; ++i)
		cin >> vec_data[i].first >> vec_data[i].second;

	int result = MAX_VALUE;

	Combination(vec_data, target_alpha, temp_alpha, 0, 0, bookCount, result);

	if (result == MAX_VALUE)
		cout << -1 << '\n';
	else
		cout << result << '\n';

	return 0;
}