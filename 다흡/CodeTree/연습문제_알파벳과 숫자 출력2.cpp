#include <iostream>

using namespace std;

int main() {

    char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int n;
    cin >> n;
    int alphaIdx = 0;
    int numberIdx = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        int leftRange = n - i;
        int rightRange = i;
        for (int j = 0; j < leftRange; ++j)
        {
            cout << alpha[alphaIdx % 26] << " ";
            alphaIdx++;
        }
        for (int j = 0; j < rightRange; ++j)
        {
            cout << numbers[numberIdx % 10] << " ";
            numberIdx++;
        }
        cout << '\n';
    }

    return 0;
}