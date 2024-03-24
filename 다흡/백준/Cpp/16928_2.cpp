#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_COUNT 100

int min(int num1, int num2)
{
	return num1 < num2 ? num1 : num2;
}

struct sData
{
	int movePos;
	int count;
	bool visited;
};

void BFS(vector<sData>& board, int startPos)
{
	queue<int> q;
	q.push(startPos);
	board[startPos].visited = true;
	board[startPos].count = 0;

	while (!q.empty())
	{
		int sPos = q.front();
		q.pop();

		int _movePos = board[sPos].movePos;
		if (_movePos > 0)
		{
			int _nextPos = _movePos;
			if (_nextPos > MAX_COUNT)
				_nextPos = MAX_COUNT;

			board[_nextPos].visited = true;
			board[_nextPos].count = min(board[_nextPos].count, board[sPos].count);
			sPos = _nextPos;
		}

		if (sPos == MAX_COUNT)
		{
			break;
		}

		// 주사위 경우의 수 체크
		for (int dice = 1; dice <= 6; ++dice)
		{
			int nextPos = sPos + dice;
			// 범위체크 + 방문여부 체크
			if (0 <= nextPos && nextPos <= MAX_COUNT 
				&& board[nextPos].visited == false)
			{
				board[nextPos].visited = true;
				board[nextPos].count = min(board[sPos].count + 1, board[nextPos].count);
				q.push(nextPos);
			}
		}
	}
}

int main()
{
	int ladderCount, snakeCount;
	cin >> ladderCount >> snakeCount;

	vector<sData> board(MAX_COUNT + 1, { 0, MAX_COUNT, false });

	for (int i = 0; i < ladderCount + snakeCount; ++i)
	{
		int pos, move;
		cin >> pos >> move;
		board[pos].movePos = move;
	}

	BFS(board, 1);

	cout << board[MAX_COUNT].count << '\n';

	return 0;
}