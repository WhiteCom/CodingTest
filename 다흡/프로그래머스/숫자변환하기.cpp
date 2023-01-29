#include <string>
#include <vector>
#include <climits>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {

    for (int i = 0; i < 1000001; ++i)
    {
        dp[i] = 1000000;
    }

    dp[x] = 0;
    for (int i = x; i <= y; ++i)
    {
        if (i + n <= y)
        {
            dp[i + n] = min(dp[i + n], dp[i] + 1);
        }
        if (i * 2 <= y)
        {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        }
        if (i * 3 <= y)
        {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        }
    }

    int answer = dp[y];
    if (answer == 1000000)
        answer = -1;

    return answer;
}