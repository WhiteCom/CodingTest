#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct roomData
{
	int type;
	long long attack;
	long long hp;
};

bool Calculate(vector<roomData>& room, long long HeroAttack, long long HeroMaxHP)
{
	long long HeroCurHP = HeroMaxHP, HeroCurAttack = HeroAttack;

	for (int i = 0; i < room.size(); ++i)
	{
		// case Monster
		if (room[i].type == 1)
		{
			long long monsterAttack = room[i].attack;
			long long monsterHP = room[i].hp;

			long long temp = 1;
			if (monsterHP % HeroCurAttack == 0)
				temp = monsterHP / HeroCurAttack - 1;
			else
				temp = monsterHP / HeroCurAttack;

			HeroCurHP -= monsterAttack * temp;

			// case Hero dead
			if (HeroCurHP <= 0)
				return false;
		}
		// case Portion
		else if (room[i].type == 2)
		{
			HeroCurAttack += room[i].attack;
			HeroCurHP = HeroMaxHP < HeroCurHP + room[i].hp ? HeroMaxHP : HeroCurHP + room[i].hp;
		}
	}

	return true;
}

int main()
{
	long long roomNumber, HeroAttack;
	cin >> roomNumber >> HeroAttack;

	vector<roomData> dungeon;
	for (int i = 0; i < roomNumber; ++i)
	{
		roomData temp;
		cin >> temp.type >> temp.attack >> temp.hp;
		dungeon.push_back(temp);
	}

	// Binary Search
	long long start = 1;
	long long end = std::numeric_limits<long long>::max() - 1;
	long long mid;

	long long answer = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (true == Calculate(dungeon, HeroAttack, mid))
		{
			end = mid - 1;
			answer = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << answer << '\n';

	return 0;
}