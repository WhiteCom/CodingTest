#include <string>
#include <vector>

using namespace std;

/*
1. 초당 회복량만큼 회복되며, 시전시간만큼 계속 회복을 성공한 경우, 추가회복량만큼 회복
2. 현재 시간에 공격을 받은 경우, 회복 불가, 몬스터 공격력만큼 체력 감소, 연속성공횟수 0으로 세팅
3. 체력이 0이하로 되면 -1 반환

output : 주어진 시간이 지난 후, 현재 캐릭터의 남은 체력을 출력

bandage : [시전시간, 초당 회복량, 추가 회복량]
attacks : [공격시간, 피해량] => 공격시간 기준 오름차순
*/

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {

    // 초기 캐릭터 체력은 최대체력을 가짐
    int curHP = health;

    int periodTick = bandage[0];
    int periodRecovery = bandage[1];
    int extraRecovery = bandage[2];

    int curTime = 0; // 현재 시간
    int injuryTime = 0; // 부상당한 시점의 시간
    int recoverySuccessCount = 0; // 연속 회복 성공한 횟수

    int answer = 0;

    int curMonsterIndex = 0;
    while (curMonsterIndex < attacks.size())
    {
        // 현재 시간이 몬스터가 공격하는 시간인경우
        if (curTime == attacks[curMonsterIndex][0])
        {
            curHP -= attacks[curMonsterIndex][1];
            recoverySuccessCount = 0;

            // 캐릭터 체력이 0이하면 반복문 종료
            if (curHP <= 0)
                break;

            // 현재 몬스터가 공격을 끝낸 경우, 다음 몬스터로 넘어가기
            curMonsterIndex++;
        }
        // 회복하는 경우
        else
        {
            curHP += periodRecovery;

            recoverySuccessCount++;
            if (recoverySuccessCount == periodTick)
            {
                curHP += extraRecovery;
                recoverySuccessCount = 0;
            }

            if (curHP > health)
                curHP = health;
        }

        curTime++;
    }

    return curHP <= 0 ? -1 : curHP;
}