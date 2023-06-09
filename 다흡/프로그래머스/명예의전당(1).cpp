#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < score.size(); ++i)
    {
        if (pq.size() < k)
        {
            pq.push(score[i]);
            if (answer.size() > 0 && answer[answer.size() - 1] < score[i])
                answer.push_back(answer[answer.size() - 1]);
            else
                answer.push_back(score[i]);
        }
        else
        {
            if (score[i] > pq.top())
            {
                pq.pop();
                pq.push(score[i]);
            }
            answer.push_back(pq.top());
        }
    }

    return answer;
}