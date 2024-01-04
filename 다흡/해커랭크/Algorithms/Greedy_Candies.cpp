// URL : https://www.hackerrank.com/challenges/candies/problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long candies(int n, vector<int> arr) {
    long answer = 0;

    // candies 
    vector<int> candies = { 1 };
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            candies.push_back(candies[(candies.size() - 1)] + 1);
        }
        else
        {
            candies.push_back(1);
        }
    }

    reverse(arr.begin(), arr.end());
    reverse(candies.begin(), candies.end());

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            if (candies[i] <= candies[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
    }

    // answer
    for (int i = 0; i < candies.size(); i++)
    {
        cout << candies[i] << " ";
        answer += candies[i];
    }

    return answer;
}