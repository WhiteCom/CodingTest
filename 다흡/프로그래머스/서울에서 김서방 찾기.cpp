#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    string beginString = "김서방은 ";
    string endString = "에 있다";
    for (int i = 0; i < seoul.size(); ++i)
    {
        if (seoul[i] == "Kim")
        {
            answer = beginString + to_string(i) + endString;
            break;
        }
    }

    return answer;
}