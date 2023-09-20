#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> primaryArr;

void isPrime(int num)
{
    if (num < 2) return;

    for (int i = 2; i * i <= num; ++i)
    {
        if (primaryArr[i])
            for (int j = i * i; j <= num; j += i)
                primaryArr[j] = false;
    }
}

int solution(int n) {
    int answer = 0;

    primaryArr = vector<bool>(n + 1, true);

    isPrime(n);

    for (int i = 2; i <= n; ++i)
    {
        primaryArr[i] ? ++answer : 0;
    }

    return answer;
}