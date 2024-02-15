#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

int primeCount(long n) {

    if (n < 2)
        return 0;

    vector<bool> arrPrimeCheck(101, true);

    // use Erastos
    for (int i = 2; i * i <= 100; ++i)
    {
        if (arrPrimeCheck[i] == true)
        {
            for (int j = i * i; j <= 100; j += i)
                arrPrimeCheck[j] = false;
        }
    }

    long long result = 0;
    unsigned long long mul = 1;
    for (int i = 2; i <= 100; ++i)
    {
        if (arrPrimeCheck[i] == true)
        {
            mul *= i;
            if (mul > n)
                break;
            else if (mul == n)
            {
                result++;
                break;
            }
            result++;
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

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
