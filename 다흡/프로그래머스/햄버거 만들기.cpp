#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    vector<int> test_stack;

    // 1, 2, 3, 1 순서
    for (int i = 0; i < ingredient.size(); ++i)
    {
        test_stack.push_back(ingredient[i]);
        if (test_stack.size() > 3)
        {
            int tSize = test_stack.size();

            if (test_stack[tSize - 4] == 1
                && test_stack[tSize - 3] == 2
                && test_stack[tSize - 2] == 3
                && test_stack[tSize - 1] == 1)
            {
                answer++;
                test_stack.pop_back();
                test_stack.pop_back();
                test_stack.pop_back();
                test_stack.pop_back();
            }
        }
    }

    return answer;
}