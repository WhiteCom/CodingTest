#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;

    int commonSize = common.size();

    int d = 0;
    int r = 0;

    d = common[1] - common[0];
    r = common[1] / common[0];

    if (common[0] + (commonSize - 1) * d == common[commonSize - 1])
        answer = common[commonSize - 1] + d;
    else
        answer = common[commonSize - 1] * r;

    return answer;
}