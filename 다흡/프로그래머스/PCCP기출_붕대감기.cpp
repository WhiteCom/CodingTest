#include <string>
#include <vector>

using namespace std;

/*
1. �ʴ� ȸ������ŭ ȸ���Ǹ�, �����ð���ŭ ��� ȸ���� ������ ���, �߰�ȸ������ŭ ȸ��
2. ���� �ð��� ������ ���� ���, ȸ�� �Ұ�, ���� ���ݷ¸�ŭ ü�� ����, ���Ӽ���Ƚ�� 0���� ����
3. ü���� 0���Ϸ� �Ǹ� -1 ��ȯ

output : �־��� �ð��� ���� ��, ���� ĳ������ ���� ü���� ���

bandage : [�����ð�, �ʴ� ȸ����, �߰� ȸ����]
attacks : [���ݽð�, ���ط�] => ���ݽð� ���� ��������
*/

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {

    // �ʱ� ĳ���� ü���� �ִ�ü���� ����
    int curHP = health;

    int periodTick = bandage[0];
    int periodRecovery = bandage[1];
    int extraRecovery = bandage[2];

    int curTime = 0; // ���� �ð�
    int injuryTime = 0; // �λ���� ������ �ð�
    int recoverySuccessCount = 0; // ���� ȸ�� ������ Ƚ��

    int answer = 0;

    int curMonsterIndex = 0;
    while (curMonsterIndex < attacks.size())
    {
        // ���� �ð��� ���Ͱ� �����ϴ� �ð��ΰ��
        if (curTime == attacks[curMonsterIndex][0])
        {
            curHP -= attacks[curMonsterIndex][1];
            recoverySuccessCount = 0;

            // ĳ���� ü���� 0���ϸ� �ݺ��� ����
            if (curHP <= 0)
                break;

            // ���� ���Ͱ� ������ ���� ���, ���� ���ͷ� �Ѿ��
            curMonsterIndex++;
        }
        // ȸ���ϴ� ���
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