#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Reference : https://en.cppreference.com/w/cpp/algorithm/next_permutation
template<class BidirIt>
bool my_next_permutation(BidirIt first, BidirIt last)
{
	auto r_first = std::make_reverse_iterator(last);
	auto r_last = std::make_reverse_iterator(first);
	auto left = std::is_sorted_until(r_first, r_last);

	if (left != r_last)
	{
		auto right = std::upper_bound(r_first, left, *left);
		std::iter_swap(left, right);
	}
	std::reverse(left.base(), last);
	return left != r_last;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	while (num--)
	{
		string input, ans;
		int count = 0;

		cin >> input;

		/*
		정렬도 필요없음.
		문제에서의 요구사항은 주어진 사전순으로,
		주어진 문자열의 다음 문자를 출력하는 것 ( ++count 가 그 의미임 )
		*/
		do
		{
			ans = input;
			if (++count == 2) break;
		} while (my_next_permutation(input.begin(), input.end()));

		cout << ans << '\n';
	}
	
	return 0;
}