#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    // solution 2 : 스택 이용
    stack<int> index_stack;

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (index_stack.empty() || numbers[i] < numbers[i - 1])
        {
            index_stack.push(i);
        }
        else
        {
            while (!index_stack.empty() && numbers[index_stack.top()] < numbers[i])
            {
                int nextNum = index_stack.top();
                index_stack.pop();
                answer[nextNum] = numbers[i];
            }
            index_stack.push(i);
        }
    }

    return answer;
}