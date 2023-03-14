#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> common_number(int n)
{
    vector<int> vec;
    for (int i = 1; i * i <= n; ++i)
    {
        if (i * i == n)
        {
            // 임의의 숫자를 집어넣음.
            vec.push_back(1);
        }
        else if (n % i == 0)
        {
            vec.push_back(1);
            vec.push_back(1);
        }
    }

    return vec;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> ansGroup;
    for (int i = 1; i <= number; ++i)
    {
        vector<int> vec = common_number(i);

        if (vec.size() > limit)
        {
            ansGroup.push_back(power);
        }
        else
        {
            ansGroup.push_back(vec.size());
        }
    }

    for (int i = 0; i < ansGroup.size(); ++i)
    {
        answer += ansGroup[i];
    }

    return answer;
}