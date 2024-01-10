#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

bool isPattern(vector<string>& bigGrid, vector<string>& smallGrid, int row, int col)
{
    int smallRow = smallGrid.size();
    int smallCol = smallGrid[0].size();

    for (int i = 0; i < smallRow; ++i)
    {
        if (bigGrid[row + i].substr(col, smallCol) != smallGrid[i])
            return false;
    }
    return true;
}

string gridSearch(vector<string> G, vector<string> P) {
    int G_rowSize = G.size();
    int G_colSize = G[0].length();

    int P_rowSize = P.size();
    int P_colSize = P[0].length();

    for (int i = 0; i <= G_rowSize - P_rowSize; ++i)
    {
        for (int j = 0; j <= G_colSize - P_colSize; ++j)
        {
            if (G[i][j] == P[0][0]
                && isPattern(G, P, i, j))
            {
                return "YES";
            }
        }
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
