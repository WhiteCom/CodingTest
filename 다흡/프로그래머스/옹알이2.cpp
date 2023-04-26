
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for (int i = 0; i < babbling.size(); ++i)
    {
        bool check = true;
        int flag = 0;
        for (int j = 0; j < babbling[i].length(); ++j)
        {
            if (babbling[i].substr(j, 3) == "aya" && flag != 1)
            {
                flag = 1;
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ye" && flag != 2)
            {
                flag = 2;
                j += 1;
            }
            else if (babbling[i].substr(j, 3) == "woo" && flag != 3)
            {
                flag = 3;
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ma" && flag != 4)
            {
                flag = 4;
                j += 1;
            }
            else
            {
                check = false;
            }
        }
        if (check)
            answer++;
    }
    return answer;
}