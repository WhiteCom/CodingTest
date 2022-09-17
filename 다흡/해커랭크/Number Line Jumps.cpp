#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

/*
* URL : https://www.hackerrank.com/challenges/kangaroo/problem
등차수열의 합
Sn = n ( 2 * a + ( n - 1 ) * d ) / 2;
*/

string kangaroo(int x1, int v1, int x2, int v2)
{
    int cnt = 1;
    int s1 = 0, s2 = 0;
    while (true)
    {
        if (cnt > 100000) break;
        s1 = cnt * (2 * x1 + (cnt - 1) * v1) / 2;
        s2 = cnt * (2 * x2 + (cnt - 1) * v2) / 2;

        if (s1 == s2) break;

        cnt++;
    }

    if (cnt < 100000)
        return "YES";
    else
        return "NO";
}