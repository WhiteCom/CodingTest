#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {

    int maxRow = board.size();
    int maxCol = board[0].size();

    string curColor = board[h][w];
    int count = 0;

    if (w - 1 > -1)
    {
        string leftColor = board[h][w - 1];
        if (curColor == leftColor)
            count++;
    }

    if (w + 1 < maxCol)
    {
        string rightColor = board[h][w + 1];
        if (curColor == rightColor)
            count++;
    }

    if (h - 1 > -1)
    {
        string upColor = board[h - 1][w];
        if (curColor == upColor)
            count++;
    }

    if (h + 1 < maxRow)
    {
        string downColor = board[h + 1][w];
        if (curColor == downColor)
            count++;
    }

    return count;
}