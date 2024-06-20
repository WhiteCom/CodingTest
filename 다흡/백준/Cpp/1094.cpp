#include <iostream>
#include <vector>

using namespace std;

int Function1(int targetLength)
{
	int count = 0;

	// 64
	bool first = targetLength & 64;
	if (first)
	{
		targetLength -= 64;
		count++;
	}

	// 32
	bool second = targetLength & 32;
	if (second)
	{
		targetLength -= 32;
		count++;
	}

	// 16
	bool third = targetLength & 16;
	if (third)
	{
		targetLength -= 16;
		count++;
	}

	// 8
	bool fourth = targetLength & 8;
	if (fourth)
	{
		targetLength -= 8;
		count++;
	}

	// 4
	bool fifth = targetLength & 4;
	if (fifth)
	{
		targetLength -= 4;
		count++;
	}

	// 2
	bool sixth = targetLength & 2;
	if (sixth)
	{
		targetLength -= 2;
		count++;
	}

	// 1
	bool seventh = targetLength & 1;
	if (seventh)
	{
		targetLength -= 1;
		count++;
	}

	return count;
}

int main()
{
	int targetLength;
	cin >> targetLength;

	int count = 0;
	
	count = Function1(targetLength);

	cout << count << '\n';

	return 0;
}