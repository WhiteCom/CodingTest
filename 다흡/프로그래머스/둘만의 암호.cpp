#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0; i<s.length(); ++i)
    {
        int t = 0;
        int c = s[i] - 'a';
        while(t < index)
        {
            c++;
            s[i] = (c % 26) + 'a';
            if(skip.find(s[i]) == string::npos)
            {
               t++;
            }
        }
        answer += s[i];
    }
    
    return answer;
}