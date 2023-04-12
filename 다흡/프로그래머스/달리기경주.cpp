#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    // 선수들 이름, 순위 저장
    map<string, int> playerRanking;
    map<int, string> playerRanking2;

    for (int i = 0; i < players.size(); ++i)
    {
        string name = players[i];
        int rank = i;
        playerRanking[name] = i;
        playerRanking2[i] = name;
    }

    // 여기서부터 순위가 변동될 예정
    for (int i = 0; i < callings.size(); ++i)
    {
        // 순위가 0위인 경우는 없다고 가정
        string backName = callings[i];

        // 기존 뒷 선수 순위 저장
        int backRank = playerRanking[backName];

        // 기존 앞 선수 이름 저장
        string frontName = playerRanking2[backRank - 1];

        // 순위 및 이름 교체 
        playerRanking[backName]--; // 뒷 선수는 추월했기에 순위상승
        playerRanking[frontName]++; // 앞 선수는 추월당해서 순위하락

        playerRanking2[backRank - 1] = backName;
        playerRanking2[backRank] = frontName;
    }

    map<int, string>::iterator itr;
    for (itr = playerRanking2.begin(); itr != playerRanking2.end(); ++itr)
    {
        answer.push_back(itr->second);
    }

    return answer;
}
