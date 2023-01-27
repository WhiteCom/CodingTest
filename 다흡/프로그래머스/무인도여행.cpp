#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[101][101];

int BFS(vector<string>& maps, int y, int x)
{
    queue<pair<int, int>> q;

    q.push({ y, x });
    visit[y][x] = true;

    int sum = 0;
    sum += maps[y][x] - '0';

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    int max_Y = maps.size();
    int max_X = maps[0].size();

    while (!q.empty())
    {
        int sY = q.front().first;
        int sX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nY = sY + dy[i];
            int nX = sX + dx[i];

            // index check
            if (nX >= 0 && nX < max_X && nY >= 0 && nY < max_Y)
            {
                // visit check
                if (!visit[nY][nX] && maps[nY][nX] != 'X')
                {
                    q.push({ nY, nX });
                    visit[nY][nX] = true;
                    sum += (maps[nY][nX] - '0');
                }
            }
        }
    }

    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (!visit[i][j] && maps[i][j] != 'X')
            {
                int result = BFS(maps, i, j);
                answer.push_back(result);
            }
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}