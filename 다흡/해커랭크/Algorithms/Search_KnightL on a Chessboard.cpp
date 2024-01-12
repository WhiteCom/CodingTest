#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'knightlOnAChessboard' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */

struct knight
{
    int row, col, count;
};

int BFS(int r, int c, int n)
{
    vector< vector<bool>> visited(n, vector<bool>(n, false));

    int knightMove[8][2] = {
        {-r, -c}, {-c, -r}, {-r, c}, {-c, r},
        {r, -c}, {c, -r}, {r, c}, {c, r}
    };

    queue<knight> q;
    q.push({ 0, 0, 0 });
    visited[0][0] = true;

    while (!q.empty())
    {
        int _row = q.front().row;
        int _col = q.front().col;
        int _count = q.front().count;

        // go to detination (n-1, n-1)
        if (_row == n - 1 && _col == n - 1)
            return _count;

        q.pop();

        for (int i = 0; i < 8; ++i)
        {
            int nextRow = _row + knightMove[i][0];
            int nextCol = _col + knightMove[i][1];

            if (nextRow >= 0 && nextRow < n
                && nextCol >= 0 && nextCol < n
                && visited[nextRow][nextCol] == false)
            {
                q.push({ nextRow, nextCol, _count + 1 });
                visited[nextRow][nextCol] = true;
            }
        }
    }

    // if cannot go to destination (n-1, n-1)
    return -1;
}

vector<vector<int>> knightlOnAChessboard(int n) {

    // result matrix's size is (n-1)*(n-1) 
    vector< vector<int>> result(n - 1, vector<int>(n - 1, 0));

    // All of cases for custom knight's moving in chess board.
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            result[i - 1][j - 1] = BFS(i, j, n);
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
