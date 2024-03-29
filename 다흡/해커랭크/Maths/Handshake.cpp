#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'handshake' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int handshake(int n) {
    // 1 -> 2, 2 -> 3, 3 -> 4, 4 -> 5, ... ,(n-1) -> n

    // Equivalent sequence
    // n : (n-1), d : 1
    // sum = ( n(a0 + l) / 2 ) or ( n(2a0 + (n-1)d) / 2 )
    // this case choose second solution
    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        result = (n - 1) * n / 2;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = handshake(n);

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
