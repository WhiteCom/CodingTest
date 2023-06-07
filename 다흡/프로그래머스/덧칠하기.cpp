#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int start = section[0];
    int end = start + m - 1;

    for (int i = 1; i < section.size(); ++i)
    {
        if (end >= section[i])
            continue;

        start = section[i];
        end = start + m - 1;
        answer++;
    }
    answer++;


    return answer;
}