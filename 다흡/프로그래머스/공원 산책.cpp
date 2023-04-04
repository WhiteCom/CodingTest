#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int posX, posY;
    int maxY = park.size();
    int maxX = park[0].length();

    // Find Start Position
    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].length(); ++j)
        {
            if (park[i][j] == 'S')
            {
                posY = i;
                posX = j;
            }
        }
    }

    for (int i = 0; i < routes.size(); ++i)
    {
        char dir = routes[i][0];
        int move = routes[i][2] - '0';

        // 따질 조건들 
        // 1. 공원 X, Y 범위체크
        // 2. 장애물 체크
        if (routes[i][0] == 'E')
        {
            bool flag = false;
            for (int j = 1; j <= move; ++j)
            {
                if (posX + j > -1 && posX + j < maxX)
                {
                    if (park[posY][posX + j] == 'X')
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                posX += move;
        }
        else if (routes[i][0] == 'W')
        {
            bool flag = false;
            for (int j = 1; j <= move; ++j)
            {
                if (posX - j > -1 && posX - j < maxX)
                {
                    if (park[posY][posX - j] == 'X')
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                posX -= move;
        }
        else if (routes[i][0] == 'S')
        {
            bool flag = false;
            for (int j = 1; j <= move; ++j)
            {
                if (posY + j > -1 && posY + j < maxY)
                {
                    if (park[posY + j][posX] == 'X')
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                posY += move;
        }
        else if (routes[i][0] == 'N')
        {
            bool flag = false;
            for (int j = 1; j <= move; ++j)
            {
                if (posY - j > -1 && posY - j < maxY)
                {
                    if (park[posY - j][posX] == 'X')
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                posY -= move;
        }
    }

    answer.push_back(posY);
    answer.push_back(posX);

    return answer;
}