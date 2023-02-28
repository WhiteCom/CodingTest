#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int last_len = t.length() - p.length() + 1;
    int p_len = p.length();
    long long p_num = stoll(p);

    for (int i = 0; i < last_len; ++i)
    {
        string sub = t.substr(i, p_len);
        long long num = stoll(sub);
        if (num <= p_num)
        {
            answer++;
        }
    }

    return answer;
}