#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    deque<char> balancedFood;
    balancedFood.push_back('0');

    // check food
    for (int i = food.size() - 1; i > 0; --i)
    {
        int mok = food[i] / 2;
        if (mok > 0)
        {
            for (int j = 0; j < mok; ++j)
            {
                balancedFood.push_front(i + '0');
                balancedFood.push_back(i + '0');
            }
        }
    }

    for (int i = 0; i < balancedFood.size(); ++i)
    {
        answer.push_back(balancedFood[i]);
    }

    return answer;
}