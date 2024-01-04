#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N;

    vector<int> arr(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    cin >> Q;
    vector<int>::iterator low;
    for (int i = 0; i < Q; ++i)
    {
        int queryNum;
        cin >> queryNum;
        low = lower_bound(arr.begin(), arr.end(), queryNum);
        if (*low == queryNum)
            cout << "Yes " << low - arr.begin() + 1 << '\n';
        else
            cout << "No " << low - arr.begin() + 1 << '\n';
    }

    return 0;
}
