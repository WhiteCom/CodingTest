#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {

    enum MONTH
    {
        JANUARY = 0,
        FEBRUARY = 1,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER,
    };

    int daysInGregorian[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int daysInJulian[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool isJulian = false;
    if (year >= 1700 && year <= 1917)
        isJulian = true;

    if (year % 400 == 0
        || (year % 4 == 0 && year % 100 != 0))
        daysInGregorian[FEBRUARY] = 29;

    if (year % 4 == 0)
        daysInJulian[FEBRUARY] = 29;

    if (year == 1918)
    {
        // In 1918 First day is 14th day
        daysInGregorian[FEBRUARY] -= 13;
    }

    int month = 1;
    int day = 256;

    for (int i = 0; i < 12; ++i)
    {
        if (day < 1)
        {
            if (isJulian)
                day += daysInJulian[i - 1];
            else
                day += daysInGregorian[i - 1];
            month--;
            break;
        }
        if (isJulian)
            day -= daysInJulian[i];
        else
            day -= daysInGregorian[i];
        month++;
    }

    string strYear = to_string(year);
    string strMonth = month < 10 ? ('0' + to_string(month)) : to_string(month);
    string strDay = day < 10 ? ('0' + to_string(day)) : to_string(day);
    string result = strDay + '.' + strMonth + '.' + strYear;

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
