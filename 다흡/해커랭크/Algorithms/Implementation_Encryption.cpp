#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {

    int strLength = s.length();
    int cols = ceil(sqrt(strLength));

    string result = "";
    for (int j = 0; j < cols; ++j)
    {
        for (int i = j; i < strLength; i += cols)
            result += s[i];

        result += ' ';
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
