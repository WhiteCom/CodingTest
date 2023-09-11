#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

bool isOddEven(int num)
{
    if (num % 2 == 0)
        return true; // even number
    return false; // odd number
}

int solution(vector<int> num_list) {
    int answer = 0;

    vector<int> odd_num;
    vector<int> even_num;

    for (int i = 0; i < num_list.size(); ++i)
    {
        if (isOddEven(num_list[i]))
            even_num.push_back(num_list[i]);
        else
            odd_num.push_back(num_list[i]);
    }

    int num1 = 0; // Odd number
    int num2 = 0; // Even number

    for (int i = 0; i < odd_num.size(); ++i)
        num1 += odd_num[i] * pow(10, (odd_num.size() - 1) - i);

    for (int i = 0; i < even_num.size(); ++i)
        num2 += even_num[i] * pow(10, (even_num.size() - 1) - i);

    answer = num1 + num2;

    return answer;
}