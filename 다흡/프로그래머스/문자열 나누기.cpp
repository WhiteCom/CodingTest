#include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(string s) {
    int answer = 0;

    int cnt1 = 0;
    int cnt2 = 0;

    char k;
    for (int i = 0; i < s.length(); ++i)
    {
        if (cnt1 == cnt2)
        {
            answer += 1;
            k = s[i];
        }
        if (k == s[i])
        {
            cnt1 += 1;
        }
        else
        {
            cnt2 += 1;
        }
    }

    return answer;
}