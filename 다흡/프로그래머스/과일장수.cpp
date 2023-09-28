#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), compare);
    const int scoreSize = score.size();
    for (int i = m - 1; i < scoreSize; i += m)
    {
        answer += (m * score[i]);
    }

    return answer;
}