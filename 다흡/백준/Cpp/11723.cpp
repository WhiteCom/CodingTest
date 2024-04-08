#include <iostream>
#include <vector>
#include <string>
#include <sstream> // getline 함수 이용하기 위한 용도

using namespace std;

// (1 <= x <= 20)
// add x : S에 x 를 추가, x가 이미 있는 경우에는 연산무시
// remove x : S에서 x를 제거한다 S에 x가 없는경우 연산무시
// check x : S에 x가 있으면 1, 없으면 0을 출력
// toggle x : S에 x가 있으면 x를 제거, 없으면 x를 추가
// all : S를 {1, 2, ... , 20} 으로 바꾼다.
// empty : S를 공집합으로 바꾼다. 

// 연산의 수 M ( 1 <= M <= 3,000,000 )

// 출력연산 : check

void Add(vector<int>& numbers, int target)
{
	// Check Range
	if (target < 0 || target > 20)
		return;

	if (numbers[target] == 0)
		numbers[target] = 1;
}

void Remove(vector<int>& numbers, int target)
{
	// Check Range
	if (target < 0 || target > 20)
		return;

	if (numbers[target] == 1)
		numbers[target] = 0;
}

void Check(vector<int>& numbers, int target)
{
	// Check Range
	if (target < 0 || target > 20)
		return; 

	cout << (numbers[target] == 1) ? 1 : 0;
	cout << '\n';
}

void Toggle(vector<int>& numbers, int target)
{
	// Check Range
	if (target < 0 || target > 20)
		return;

	if (numbers[target] == 1)
		numbers[target] = 0;
	else if (numbers[target] == 0)
		numbers[target] = 1;
}

void All(vector<int>& numbers)
{
	for (int i = 0; i <= 20; ++i)
		numbers[i] = 1;
}

void Empty(vector<int>& numbers)
{
	for (int i = 0; i <= 20; ++i)
		numbers[i] = 0;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;

	// LookUp 테이블, 해당 숫자가 있는지 체크하는 배열
	// 0 : 해당 값 없음
	// 1 : 해당 값 있음
	vector<int> numbers(21, 0);

	// 개행문자 입력 무시
	cin.ignore();
	for (int i = 0; i < M; ++i)
	{
		// token 을 이용한 문자열 자르기 연산 들어갈 경우, 시간초과 발생.
		string line;
		getline(cin, line);

		if (line[0] == 'a' && line[1] == 'd') // add
		{
			int num = line[4] - '0';
			Add(numbers, num);
		}
		else if (line[0] == 'r') // remove
		{
			int num = line[7] - '0';
			Remove(numbers, num);
		}
		else if (line[0] == 'c') // check
		{
			int num = line[6] - '0';
			Check(numbers, num);
		}
		else if (line[0] == 't') // toggle
		{
			int num = line[7] - '0';
			Toggle(numbers, num);
		}
		else if (line[0] == 'a' && line[1] == 'l') // all
		{
			All(numbers);
		}
		else if (line[0] == 'e') // empty
		{
			Empty(numbers);
		}
	}

	return 0;
}