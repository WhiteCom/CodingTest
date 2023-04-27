#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    vector<int> X_arr(10, 0);
    vector<int> Y_arr(10, 0);

    vector<int> Re_arr(10, 0);

    for (int i = 0; i < X.length(); ++i)
    {
        int num = X[i] - '0';
        X_arr[num]++;
    }

    for (int i = 0; i < Y.length(); ++i)
    {
        int num = Y[i] - '0';
        Y_arr[num]++;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (X_arr[i] == 0 || Y_arr[i] == 0)
            continue;

        int minCnt = X_arr[i] > Y_arr[i] ? Y_arr[i] : X_arr[i];
        cout << minCnt << '\n';
        Re_arr[i] = minCnt;
    }

    for (int i = 9; i > -1; --i)
    {
        if (Re_arr[i] > 0)
        {
            for (int j = 0; j < Re_arr[i]; ++j)
            {
                answer += (i + '0');
                if (i == 0 && answer.length() < 2) break;
            }
        }
    }

    if (answer.empty())
        answer = "-1";


    return answer;
}