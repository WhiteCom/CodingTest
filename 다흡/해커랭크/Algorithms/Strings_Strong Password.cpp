//=======================================================================================
// URL : https://www.hackerrank.com/challenges/strong-password/problem?isFullScreen=true
//=======================================================================================

#include <iostream>
#include <string>

using namespace std;

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_key = "!@#$%^&*()-+";

    int result = 0;

    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;

    for (int i = 0; i < password.length(); i++)
    {
        // case 1 : one digit
        for (int j = 0; !flag1 && j < numbers.length(); j++)
        {
            if (password[i] == numbers[j])
            {
                flag1 = true;
                break;
            }
        }

        // case 2 : lower_case
        for (int j = 0; !flag2 && j < lower_case.length(); j++)
        {
            if (password[i] == lower_case[j])
            {
                flag2 = true;
                break;
            }
        }

        // case 3 : upper_case
        for (int j = 0; !flag3 && j < upper_case.length(); j++)
        {
            if (password[i] == upper_case[j])
            {
                flag3 = true;
                break;
            }
        }

        // case 4 : special_key
        for (int j = 0; !flag4 && j < special_key.length(); j++)
        {
            if (password[i] == special_key[j])
            {
                flag4 = true;
                break;
            }
        }
    }
    if (!flag1)
        result++;
    if (!flag2)
        result++;
    if (!flag3)
        result++;
    if (!flag4)
        result++;

    // Last case ( length < 6 )
    if (result + password.length() < 6)
        result = 6 - password.length();

    return result;
}