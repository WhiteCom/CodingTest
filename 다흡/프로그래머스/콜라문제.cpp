#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int bottle = n;
    int getBottle = 0;

    while (bottle >= a)
    {
        getBottle = bottle / a * b;
        bottle = bottle - (bottle / a * a) + getBottle;
        // cout << bottle << " " << getBottle << '\n';
        answer += getBottle;
    }
    cout << bottle;

    return answer;
}
