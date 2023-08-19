#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int changeNumber(int a, int b)
{
    int resultNum = 0;

    char result[10];
    char num1[5];
    char num2[5];

    sprintf(num1, "%d", a);
    sprintf(num2, "%d", b);

    int offset = 0;
    memcpy(result + offset, num1, sizeof(num1));
    offset += strlen(num1);
    memcpy(result + offset, num2, sizeof(num2));

    int len = strlen(result);
    if (len > 1)
    {
        for (int i = len - 1; i > -1; i--)
            resultNum += (result[i] - '0') * pow(10, len - i - 1);
    }
    else
        resultNum = (resultNum - '0');

    return resultNum;
}

int solution(int a, int b) {
    int answer = 0;
    int num1 = changeNumber(a, b);
    int num2 = changeNumber(b, a);

    answer = num1 >= num2 ? num1 : num2;

    return answer;
}