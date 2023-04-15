#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end());

    // 1. 처음 폭격범위에 대한 길이 구하기
    int bomb_first = targets[0][0];
    int bomb_second = targets[0][1];
    answer++;
    for (int i = 0; i < targets.size(); ++i)
    {
        // 2. 다음 폭격범위의 시작점이 처음 폭격범위를 벗어나는지 체크
        if (bomb_second <= targets[i][0])
        {
            // 3-1. 폭격범위를 벗어나면 처음 폭격범위 갱신, answer++
            bomb_first = targets[i][0];
            bomb_second = targets[i][1];
            answer++;
        }
        else if (bomb_second > targets[i][1])
        {
            // 3-2. 중간에 기존보다 시작점은 크나, 끝지점이 작은경우 갱신
            bomb_second = targets[i][1];
        }
        // 4. targets 끝날때까지 1~3 반복
    }

    return answer;
}