#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct sData
{
	int value;
	int index;
};

bool Compare(sData s1, sData s2)
{
	return s1.value < s2.value;
}

bool Compare2(sData s1, sData s2)
{
	return s1.index < s2.index;
}

vector<sData> CompressCoords(vector<int>& coords)
{
	int coordsLen = coords.size();
	vector<sData> tempCoords;
	for (int i = 0; i < coordsLen; ++i)
	{
		tempCoords.push_back({ coords[i],  i });
	}

	sort(tempCoords.begin(), tempCoords.end(), Compare);

	// ��ǥ���� ����� �ε����� ������ ���̺� ����
	vector<sData> resultCoords;
	int curValue = 0;
	for (int i = 0; i < tempCoords.size(); ++i)
	{
		if (i > 0 && tempCoords[i].value != tempCoords[i - 1].value)
		{
			curValue++;
		}
		
		resultCoords.push_back({ curValue, tempCoords[i].index });
	}

	sort(resultCoords.begin(), resultCoords.end(), Compare2);

	return resultCoords;
}

int main()
{
	int num;
	cin >> num;

	// ���� ���ڰ� �迭�� �ְ�, 
	// �迭�̿������� ���������� �ε����� ���° �ε����� �ִ��� �����ϴ� ����.
	vector<int> coords(num, 0);
	for (int i = 0; i < num; ++i)
	{
		cin >> coords[i];
	}

	vector<sData> compressed_coords = CompressCoords(coords);
	for (int i = 0; i < compressed_coords.size(); ++i)
	{
		cout << compressed_coords[i].value << " ";
	}
	cout << '\n';

	return 0;
}