#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (int i = 0; i < balls.size(); ++i)
    {
        // 4개의 축 체크 (상하좌우)
        int x1 = balls[i][0];
        int y1 = balls[i][1];

        // 왼쪽 대칭
        int left_X = startX * -1;
        int left_Y = startY;
        int left_D = (x1 - left_X) * (x1 - left_X) + (y1 - left_Y) * (y1 - left_Y);
        if (y1 == startY && x1 < startX) // 벽에 안맞고 타겟에 맞는경우
        {
            left_D = INT_MAX;
        }

        // 오른쪽 대칭
        int right_X = m + (m - startX);
        int right_Y = startY;
        int right_D = (x1 - right_X) * (x1 - right_X) + (y1 - right_Y) * (y1 - right_Y);
        if (y1 == startY && x1 > startX) // 벽에 안 맞고 타겟에 맞는경우
        {
            right_D = INT_MAX;
        }

        // 아래쪽 대칭
        int bottom_X = startX;
        int bottom_Y = startY * -1;
        int bottom_D = (x1 - bottom_X) * (x1 - bottom_X) + (y1 - bottom_Y) * (y1 - bottom_Y);
        if (x1 == startX && y1 < startY) // 벽에 안맞고 타겟에 맞는경우
        {
            bottom_D = INT_MAX;
        }

        // 위쪽 대칭
        int top_X = startX;
        int top_Y = n + (n - startY);
        int top_D = (x1 - top_X) * (x1 - top_X) + (y1 - top_Y) * (y1 - top_Y);
        if (x1 == startX && y1 > startY)
        {
            top_D = INT_MAX;
        }

        int result = min(left_D, min(right_D, min(bottom_D, top_D)));
        answer.push_back(result);
    }

    return answer;
}