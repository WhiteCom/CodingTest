#include <iostream>
#include <vector>

#define MAX_NUM 15

using namespace std;

int abs(int num)
{
	if (num < 0)
		return num * -1;
	
	return num;
}

bool Check(vector<int>& col, int level)
{
	for (int i = 0; i < level; ++i)
	{
		// 대각선이거나 같은 라인
		if (col[i] == col[level] || abs(col[level] - col[i]) == (level - i))
			return false;

		// col[i]가 의미하는 것이 x좌표, i가 의미하는 것이 y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
	}

	return true;
}

void NQueen(vector<int>& col, int inputNum, int x, int& total)
{
	if (x == inputNum)
	{
		total++;
	}
	else
	{
		for (int i = 0; i < inputNum; ++i)
		{
			col[x] = i; // 해당위치에 퀸을 배치
			if (Check(col, x)) // 유효하다면 다음행의 퀸 배치, 유효하지 않다면 다른 위치로 퀸 배치 변경
			{
				NQueen(col, inputNum, x + 1, total);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> column(MAX_NUM, 0);
	int result = 0;
	NQueen(column, N, 0, result);

	cout << result << '\n';
	return 0;
}