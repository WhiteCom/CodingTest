#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct sData
{
	int linkPeople[51]; // 어떤 사람이랑 연결되어있는지 체크
	bool truth; // 진실 아는지 여부
};

// 이 함수는 시작점이 진실을 아는 사람일 때, 연결된 모든 정점에 있는 사람들의 진실을 아는지 여부를 갱신하기 위한 함수이다. 
void DFS(vector<sData>& people, vector<bool>& visited, int startIndex)
{
	if (visited[startIndex] == true)
		return;

	visited[startIndex] = true;

	for (int i = 0; i < 51; ++i)
	{
		if (people[startIndex].linkPeople[i] == 1 && visited[i] == false)
		{
			people[i].truth = true;
			DFS(people, visited, i);
		}
	}
}

int main()
{
	// N, M : 사람수, 파티수
	// truthCount : 진실을 아는 사람 수

	// 각 사람들이 존재할 때, 진실을 아는 사람들과 연결된 사람들은 진실을 안다고 생각해야한다.
	// 최종적으로 다시 파티의 수를 살펴보며, 진실을 아는 사람이 포함되어있는지 체크해보며 카운팅해보기
	// 2중 작업이 필요해보임. 
	// 1. 사람 그래프간 진실 전파 관련 탐색 : 반복문 1번
	// 2. 최종적으로 거짓말을 성공할 수 있는 파티 경우의 수 찾기 : 반북문 2번

	int N, M;
	cin >> N >> M;

	int truthMan;
	cin >> truthMan;

	
	// 총 인원
	// 0. 진실을 아는 사람정보 저장
	vector<sData> people(51);

	// Init
	for (int i = 0; i < 51; ++i)
	{
		memset(people[i].linkPeople, 0x00, sizeof(int) * 51);
		people[i].truth = 0;
	}

	for (int i = 0; i < truthMan; ++i)
	{
		int truthManIndex;
		cin >> truthManIndex;
		people[truthManIndex].truth = true;
	}

	// 파티가 열림
	vector< vector<int>> partyPeoples(M); // 각 파티별 몇 명이 들어가는지 체크

	// 1. 그래프 연결 체크
	for (int i = 0; i < M; ++i)
	{
		int peopleNum;
		cin >> peopleNum;

		vector<int> partyPeople(peopleNum, 0);
		for (int j = 0; j < peopleNum; ++j)
		{
			cin >> partyPeople[j];
		}
		partyPeoples[i] = partyPeople;

		// 실제 그래프 연결 체크
		// 방향성이 없기에, 양방향 연결
		for (int j = 0; j < peopleNum - 1; ++j)
		{
			int curNum = partyPeople[j];

			for (int k = j + 1; k < peopleNum; ++k)
			{
				int nextNum = partyPeople[k];
				
				// 양방향 연결
				people[curNum].linkPeople[nextNum] = 1;
				// 진실 알게되는 여부 갱신
				if (people[nextNum].truth == true)
				{
					people[curNum].truth = true;
					people[nextNum].truth = true;
				}
				
				// 양방향 연결
				people[nextNum].linkPeople[curNum] = 1;
				// 진실 알게되는 여부 갱신
				if (people[curNum].truth == true)
				{
					people[curNum].truth = true;
					people[nextNum].truth = true;
				}
			}
		}
	}

	// 진실을 아는 사람이 없는경우, 모든 파티에서 거짓말 가능.
	if (truthMan == 0)
	{
		cout << M << '\n';
		return 0;
	}

	// 2. 다시한번 더 그래프를 탐색하면서, 진실을 아는 사람들 갱신
	for (int i = 0; i < 51; ++i)
	{
		if (people[i].truth == true)
		{
			vector<bool> visited(51, false);
			// graph, visited, start
			DFS(people, visited, i);
		}
	}

	// 3. 최종적으로 어떤 파티에서 완벽한 거짓말이 가능한지 체크
	int result = 0;
	for (int i = 0; i < M; ++i)
	{
		bool canLie = true;
		for (int j = 0; j < partyPeoples[i].size(); ++j)
		{
			int curPeople = partyPeoples[i][j];
			if (people[curPeople].truth == true)
			{
				canLie = false;
				break;
			}
		}

		if (canLie)
			result++;
	}

	cout << result << '\n';

	return 0;
}