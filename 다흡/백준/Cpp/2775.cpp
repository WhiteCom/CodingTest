#include <iostream>
#include <vector>

using namespace std;

int Sum(vector< vector<int>>& peoples, int targetFloor, int targetRoom)
{
	int result = 0;
	for (int i = 0; i <= targetRoom; ++i)
	{
		result += peoples[targetFloor - 1][i];
	}

	return result;
}

int main()
{
	int testCase;
	cin >> testCase;
	
	for (int i = 0; i < testCase; ++i)
	{
		int targetFloor, targetRoom;
		cin >> targetFloor >> targetRoom;

		// 0�� iȣ���� i���� ���. 
		vector< vector<int>> peoples(targetFloor + 1, vector<int>(targetRoom + 1, 0));
		for (int room = 1; room <= targetRoom; ++room)
			peoples[0][room] = room; 

		// k��, nȣ���� �� ���� ��°�?
		for (int floor = 1; floor <= targetFloor; ++floor)
		{
			for (int room = 1; room <= targetRoom; ++room)
			{
				peoples[floor][room] += Sum(peoples, floor, room);
				if (targetFloor == floor && targetRoom == room)
				{
					cout << peoples[floor][room] << '\n';
					break;
				}
			}
		}
	}
	
	return 0;
}