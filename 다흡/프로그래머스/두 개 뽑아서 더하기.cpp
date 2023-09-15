#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    map<int, bool> data;

    int offset = 0;
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            int sum = numbers[i] + numbers[j];

            data[sum] = true;
        }
    }

    map<int, bool>::iterator iter;
    for (iter = data.begin(); iter != data.end(); iter++)
    {
        answer.push_back(iter->first);
    }

    return answer;
}