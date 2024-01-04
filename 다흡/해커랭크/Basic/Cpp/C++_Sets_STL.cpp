#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

enum E_TYPE
{
    E_TYPE_ADD = 1,
    E_TYPE_DELETE,
    E_TYPE_PRINT,
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;

    set<int> dataSet;
    for (int i = 0; i < N; ++i)
    {
        int type, value;
        cin >> type >> value;
        switch (type)
        {
        case E_TYPE_ADD:
        {
            dataSet.insert(value);
        }
        break;
        case E_TYPE_DELETE:
        {
            dataSet.erase(value);
        }
        break;
        case E_TYPE_PRINT:
        {
            set<int>::iterator it = dataSet.find(value);
            if (it != dataSet.end())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        break;
        }
    }

    return 0;
}