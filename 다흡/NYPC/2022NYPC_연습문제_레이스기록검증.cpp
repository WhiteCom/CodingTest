#include <iostream>

using namespace std;

// URL : https://nypc.github.io/2022/round1_p1
// 레이스 기록 검증

struct UserData
{
	int startTime;
	int endTime;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	UserData* userList = new UserData[N];
	memset(userList, 0x00, sizeof(userList));

	int count = 0; // 올바르지 않은 로그파일 개수

	// 출발시간, 끝나는시간 기록
	for (int idx = 0; idx < M; ++idx)
	{
		int t, i, s;
		cin >> t >> i >> s;

		if (s == 0)
		{
			if (userList[i - 1].startTime > 0) 
				count++;

			userList[i - 1].startTime = t;
		}
		else if (s == 1)
		{
			if (userList[i - 1].endTime > 0)
				count++;

			userList[i - 1].endTime = t;
		}
		else
		{
			cout << "이상한 경우입니다.\n";
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (userList[i].endTime - userList[i].startTime < 60)
		{
			count++;
		}
	}

	if (count > 0) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}