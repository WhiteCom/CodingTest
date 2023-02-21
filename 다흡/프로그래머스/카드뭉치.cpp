#include <string>
#include <vector>
#include <iostream>

using namespace std;

// URL : https://school.programmers.co.kr/learn/courses/30/lessons/159994

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    int count = 0;

    int one_pointer = 0; // 1번 카드뭉치 index
    int two_pointer = 0; // 2번 카드뭉치 index
    for (int i = 0; i < goal.size();)
    {
        if (goal[i] == cards1[one_pointer] && one_pointer < cards1.size())
        {
            count++;
            one_pointer++;
        }

        if (goal[i] == cards2[two_pointer] && two_pointer < cards2.size())
        {
            count++;
            two_pointer++;
        }

        ++i;
    }

    if (count == goal.size())
        answer = "Yes";
    else
        answer = "No";

    return answer;
}