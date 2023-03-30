#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    map<string, int> data;

    // 현재 name, yearning 이 같다고 가정하고 진행
    for (int i = 0; i < name.size(); ++i)
    {
        data[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); ++j)
        {
            sum += data[photo[i][j]];
        }
        answer.push_back(sum);
    }

    return answer;
}