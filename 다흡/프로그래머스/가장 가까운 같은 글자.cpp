#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    map<char, int> data;
    for (int i = 0; i < s.length(); ++i)
    {
        if (data.find(s[i]) == data.end())
        {
            data[s[i]] = i;
            answer.push_back(-1);
        }
        else
        {
            int test = i - data[s[i]];
            data[s[i]] = i;
            answer.push_back(test);
        }

    }

    return answer;
}