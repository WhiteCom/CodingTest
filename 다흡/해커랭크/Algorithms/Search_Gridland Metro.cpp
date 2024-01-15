#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {

    // Note : A train track may overlap other train tracks within the same row.
    long long total = static_cast<long long>(n) * m;

    map<int, vector<int>> trainPath;
    for (int i = 0; i < k; ++i)
    {
        int r = track[i][0];
        int sC = track[i][1];
        int eC = track[i][2];

        // if not foun trainPath
        if (trainPath.find(r) == trainPath.end()) // empty case, insert
            trainPath.insert({ r, {sC, eC} });
        else if (sC > trainPath.find(r)->second[1]) // ???
            total -= eC - sC + 1;
        else if (eC > trainPath.find(r)->second[1]) // overlap case, update trainPath
            trainPath.find(r)->second[1] = eC;
    }

    map<int, vector<int>>::iterator it;
    for (it = trainPath.begin(); it != trainPath.end(); ++it)
    {
        total -= it->second[1] - it->second[0] + 1;
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<int>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    long long result = gridlandMetro(n, m, k, track);

    fout << result << "\n";

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
