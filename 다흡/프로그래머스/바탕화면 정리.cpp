#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int min_X = 1000;
    int min_Y = 1000;
    int max_X = 0;
    int max_Y = 0;

    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for (int j = 0; j < wallpaper[i].size(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                min_X = min_X > j ? j : min_X;
                min_Y = min_Y > i ? i : min_Y;
                max_X = max_X < j ? j : max_X;
                max_Y = max_Y < i ? i : max_Y;
            }
        }
    }
    answer.push_back(min_Y);
    answer.push_back(min_X);
    answer.push_back(max_Y + 1);
    answer.push_back(max_X + 1);

    return answer;
}