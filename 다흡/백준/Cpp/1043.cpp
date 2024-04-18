#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct sData
{
	int linkPeople[51]; // � ����̶� ����Ǿ��ִ��� üũ
	bool truth; // ���� �ƴ��� ����
};

// �� �Լ��� �������� ������ �ƴ� ����� ��, ����� ��� ������ �ִ� ������� ������ �ƴ��� ���θ� �����ϱ� ���� �Լ��̴�. 
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
	// N, M : �����, ��Ƽ��
	// truthCount : ������ �ƴ� ��� ��

	// �� ������� ������ ��, ������ �ƴ� ������ ����� ������� ������ �ȴٰ� �����ؾ��Ѵ�.
	// ���������� �ٽ� ��Ƽ�� ���� ���캸��, ������ �ƴ� ����� ���ԵǾ��ִ��� üũ�غ��� ī�����غ���
	// 2�� �۾��� �ʿ��غ���. 
	// 1. ��� �׷����� ���� ���� ���� Ž�� : �ݺ��� 1��
	// 2. ���������� �������� ������ �� �ִ� ��Ƽ ����� �� ã�� : �ݺϹ� 2��

	int N, M;
	cin >> N >> M;

	int truthMan;
	cin >> truthMan;

	
	// �� �ο�
	// 0. ������ �ƴ� ������� ����
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

	// ��Ƽ�� ����
	vector< vector<int>> partyPeoples(M); // �� ��Ƽ�� �� ���� ������ üũ

	// 1. �׷��� ���� üũ
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

		// ���� �׷��� ���� üũ
		// ���⼺�� ���⿡, ����� ����
		for (int j = 0; j < peopleNum - 1; ++j)
		{
			int curNum = partyPeople[j];

			for (int k = j + 1; k < peopleNum; ++k)
			{
				int nextNum = partyPeople[k];
				
				// ����� ����
				people[curNum].linkPeople[nextNum] = 1;
				// ���� �˰ԵǴ� ���� ����
				if (people[nextNum].truth == true)
				{
					people[curNum].truth = true;
					people[nextNum].truth = true;
				}
				
				// ����� ����
				people[nextNum].linkPeople[curNum] = 1;
				// ���� �˰ԵǴ� ���� ����
				if (people[curNum].truth == true)
				{
					people[curNum].truth = true;
					people[nextNum].truth = true;
				}
			}
		}
	}

	// ������ �ƴ� ����� ���°��, ��� ��Ƽ���� ������ ����.
	if (truthMan == 0)
	{
		cout << M << '\n';
		return 0;
	}

	// 2. �ٽ��ѹ� �� �׷����� Ž���ϸ鼭, ������ �ƴ� ����� ����
	for (int i = 0; i < 51; ++i)
	{
		if (people[i].truth == true)
		{
			vector<bool> visited(51, false);
			// graph, visited, start
			DFS(people, visited, i);
		}
	}

	// 3. ���������� � ��Ƽ���� �Ϻ��� �������� �������� üũ
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