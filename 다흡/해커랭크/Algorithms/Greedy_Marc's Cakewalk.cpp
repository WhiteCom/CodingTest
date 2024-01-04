// Problem URL : https://www.hackerrank.com/challenges/marcs-cakewalk/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long marcsCakewalk(vector<int> calorie) 
{
    long answer = 0;

    vector<int> temp_calorie = calorie;
    sort(temp_calorie.begin(), temp_calorie.end(), greater<int>());

    // calculate
    int calorie_num = temp_calorie.size();
    for (long i = 0; i < calorie_num; i++)
    {
        answer += pow(2, i) * temp_calorie[i];
    }

    return answer;
}