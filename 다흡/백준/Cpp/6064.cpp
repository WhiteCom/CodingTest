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
	// X �� ��ǥX �� ���߰� Y ������ ��ġ�ϴ� ��� ã��
	int curX = 1, curY = 1;

	int curCount = 0;

	// flag : ����ġ����, x, y �� �� �ϳ��� Ÿ�� ������ ������Ű��, �������� �ݺ������� Ž���ϴ� �뵵
	// false : x ����, true : y����
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
	// �ִ� ���� ������ Ž��
	while (curCount <= maxX * maxY)
	{
		// M = 8, N = 12 => target X = 8, target Y = 9
		// M = 12, N = 8 => target X = 9, target Y = 8
		if (curX == targetX && curY == targetY)
		{
			Success = true;
			break;
		}

		// x�� ����, y ���� Ž��
		if (flag == false)
		{
			curCount += maxX; 
			curY = (curY + maxX) % maxY;
			
			curY = curY == 0 ? maxY : curY; // �ִ밪 �������� 0�ΰ��, �ִ밪���� ����
		}
		// y�� ����, x ���� Ž��
		else
		{
			curCount += maxY;
			curX = (curX + maxY) % maxX;
			
			curX = curX == 0 ? maxX : curX; // �ִ밪 �������� 0�ΰ��, �ִ밪���� ����
		}
		
	}

	// ���ϴ� ���� �� ã�� ���
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