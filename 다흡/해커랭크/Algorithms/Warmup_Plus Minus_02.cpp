#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int count[3] = { 0, };
    for (int n : arr)
    {
        if (n > 0)       count[0]++;
        else if (n < 0)  count[1]++;
        else            count[2]++;
    }

    int arrSize = arr.size();
    string resultPositive = "", resultNegative = "", resultZero = "";

    string ratio[3] = { "", };

    // 0 : positive
    // 1 : negative
    // 2 : zero
    for (int i = 0; i < 3; ++i)
    {
        int mok = count[i] / arrSize;
        int mod = count[i] % arrSize;

        ratio[i].push_back('0' + mok);
        ratio[i].push_back('.');

        // decimal precision to 6
        for (int j = 0; j < 6; ++j)
        {
            mod *= 10;
            mok = (int)(mod / arrSize);
            // Case Round decimal
            // if(j == 5 && mod * 10 / arrSize > 4) mok++;
            ratio[i].push_back('0' + mok);
            mod %= arrSize;
        }

        cout << ratio[i] << '\n';
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
