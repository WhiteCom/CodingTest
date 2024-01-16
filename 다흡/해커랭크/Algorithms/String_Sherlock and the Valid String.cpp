#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {

    int minFreqeuncy = 100000;
    map<char, int> frequencyString;
    for (int i = 0; i < s.length(); ++i)
        frequencyString[s[i]]++;

    map<char, int>::iterator it;
    int flagNum = -1;
    int count = 0;
    for (it = frequencyString.begin(); it != frequencyString.end(); ++it)
    {
        if (flagNum == -1)
            flagNum = it->second;

        /*
        here i check
        1. if current frequency (i) is same as f then we can continue with loop
        2. but if (i) not same as f then we can tolerate at most 1 DIFFERENT frequency whici I am counting in int count.
        */
        if (it->second != flagNum && count == 0)
            count++;
        else if (it->second != flagNum && count > 0)
            return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
