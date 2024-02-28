#include <iostream>
#include <vector>

using namespace std;

struct sData
{
	int fiboNumber;
	int zeroCount;
	int oneCount;

	sData operator+(const sData& s) const
	{
		sData result;
		result.fiboNumber = this->fiboNumber + s.fiboNumber;
		result.zeroCount = this->zeroCount + s.zeroCount;
		result.oneCount = this->oneCount + s.oneCount;
		return result;
	}
};

sData Fibonachi(vector<sData>& arr, int n)
{
	if (arr[n].fiboNumber > 0)
		return arr[n];

	arr[n] = arr[n - 1] + arr[n - 2];
	return arr[n];
}

int main()
{
	vector<sData> fiboNumbers(41, {0, 0, 0});
	fiboNumbers[0].fiboNumber = 0;
	fiboNumbers[0].zeroCount = 1;
	fiboNumbers[0].oneCount = 0;

	fiboNumbers[1].fiboNumber = 1;
	fiboNumbers[1].zeroCount = 0;
	fiboNumbers[1].oneCount = 1;

	for (int i = 2; i <= 40; ++i)
	{
		fiboNumbers[i] = Fibonachi(fiboNumbers, i);
	}

	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		int num;
		cin >> num;

		cout << fiboNumbers[num].zeroCount << " " << fiboNumbers[num].oneCount << '\n';
	}
	return 0;
}