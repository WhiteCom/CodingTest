#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 행렬의 덧셈은 두 행렬의 크기가 같아야한다. 
    // 즉 행렬의 행, 열의 크기가 둘 다 같다는걸 전제로 깔아야함.

    int row1_Length = arr1.size();
    int col1_Length = arr1[0].size();

    vector<vector<int> > answer(row1_Length);
    for (int i = 0; i < row1_Length; ++i) {
        answer[i] = vector<int>(col1_Length, 0);
    }

    for (int i = 0; i < row1_Length; ++i) {
        for (int j = 0; j < col1_Length; ++j) {
            answer[i][j] += arr1[i][j];
        }
    }

    cout << '\n';
    int row2_Length = arr2.size();
    int col2_Length = arr2[0].size();

    for (int i = 0; i < row2_Length; ++i) {
        for (int j = 0; j < col2_Length; ++j) {
            answer[i][j] += arr2[i][j];
        }
    }

    return answer;
}