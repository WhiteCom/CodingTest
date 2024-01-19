#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {

    int left = 0;
    int right = n - 1;
    int changeCount = 0;
    string result = s;

    while (left < right)
    {
        if (result[left] != result[right])
        {
            char maxChar = result[left] - '0' > result[right] - '0' ? result[left] : result[right];
            result[left] = maxChar;
            result[right] = maxChar;
            changeCount++;
        }
        left++;
        right--;
    }

    if (changeCount > k)
        return "-1";

    left = 0;
    right = n - 1;
    while (left <= right)
    {
        if (left == right && k - changeCount > 0)
            result[left] = '9';

        else
        {
            if (result[left] < '9')
            {
                if (k - changeCount >= 2 && result[left] == s[left] && result[right] == s[right])
                {
                    result[left] = '9';
                    result[right] = '9';
                    changeCount += 2;
                }
                else if (k - changeCount >= 1 && s[left] != s[right])
                {
                    result[left] = '9';
                    result[right] = '9';
                    changeCount++;
                }
            }
        }
        left++;
        right--;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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