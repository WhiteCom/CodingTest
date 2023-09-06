#include <iostream>
#include <string>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& num_list, int target, int start, int end)
{
    if (start > end)
        return 0;
    if (start < 0 || start >= num_list.size())
        return 0;
    if (end < 0 || end >= num_list.size())
        return 0;

    int mid = (start + end) / 2;
    if (num_list[mid] == target)
        return 1;

    int left_Result = BinarySearch(num_list, target, start, mid - 1);
    int right_Result = BinarySearch(num_list, target, mid + 1, end);
    return ((left_Result == 1) || (right_Result == 1)) ? 1 : 0;
}

int solution(vector<int> num_list, int n) {
    int answer = 0;

    answer = BinarySearch(num_list, n, 0, num_list.size() - 1);
    return answer;
}

// Test Code
/*
int main()
{
    vector<int> num_list;
    for (int i = 0; i < 5; ++i)
    {
        int inp_num;
        cin >> inp_num;
        num_list.push_back(inp_num);
    }

    int targetNumber = 0;
    cin >> targetNumber;

    int answer = solution(num_list, targetNumber);

    return 0;
}
*/