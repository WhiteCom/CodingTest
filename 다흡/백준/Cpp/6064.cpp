#include <iostream>
#include <vector>

using namespace std;

struct sData
{
	int x;
	int y;
};

int CreateCustomCalendar(int maxX, int maxY, int targetX, int targetY)
{
	// X 를 목표X 에 맞추고 Y 지점이 일치하는 경우 찾기
	int curX = 1, curY = 1;

	int curCount = 0;

	// flag : 스위치변수, x, y 둘 중 하나를 타겟 값으로 고정시키고, 나머지를 반복문에서 탐색하는 용도
	// false : x 기준, true : y기준
	bool flag = false;
	if (targetX <= maxY)
	{
		curCount = targetX;
		curX = targetX;
		curY = targetX;
		flag = false;
	}
	else if (targetY <= maxX)
	{
		curCount = targetY;
		curX = targetY;
		curY = targetY;
		flag = true;
	}

	bool Success = false;
	// 최대 범위 내에서 탐색
	while (curCount <= maxX * maxY)
	{
		// M = 8, N = 12 => target X = 8, target Y = 9
		// M = 12, N = 8 => target X = 9, target Y = 8
		if (curX == targetX && curY == targetY)
		{
			Success = true;
			break;
		}

		// x값 고정, y 기준 탐색
		if (flag == false)
		{
			curCount += maxX; 
			curY = (curY + maxX) % maxY;
			
			curY = curY == 0 ? maxY : curY; // 최대값 나머지가 0인경우, 최대값으로 세팅
		}
		// y값 고정, x 기준 탐색
		else
		{
			curCount += maxY;
			curX = (curX + maxY) % maxX;
			
			curX = curX == 0 ? maxX : curX; // 최대값 나머지가 0인경우, 최대값으로 세팅
		}
		
	}

	// 원하는 값을 못 찾은 경우
	if (Success == false)
		curCount = -1;

	return curCount;
 }

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		int M, N, X, Y;

		cin >> M >> N >> X >> Y;

		// Impossible Case
		if (X > M || Y > N)
		{
			cout << -1 << '\n';
			continue;
		}

		// Create Calendar
		// Search
		cout << CreateCustomCalendar(M, N, X, Y) << '\n';
	}
	return 0;
}