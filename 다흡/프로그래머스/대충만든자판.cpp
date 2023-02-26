#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);

    for(int i=0; i<targets.size(); ++i)
    {
        int sum = 0;
        for(int j=0; j<targets[i].length(); ++j)
        {
            bool flag = false;
            int count = 101;
            for(int k=0; k<keymap.size(); ++k)
            {
                char ch = targets[i][j];
                int index = keymap[k].find(ch) + 1;
                if(keymap[k].find(ch) != string::npos)
                {
                    count = min(count, index);
                    flag = true;
                }
            }
            if(!flag)
            {
                sum = -1;
                break;
            }
            sum += count;
        }
        answer[i] = sum;
    }
    
    return answer;
}