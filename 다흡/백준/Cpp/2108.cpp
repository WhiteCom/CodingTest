#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct sData
{
	int num;
	int count;
};

int main()
{
	int num;
	cin >> num;

	vector<int> numbers(num, 0);
	map<int, int> numberCount; // key : number, value : count
	int sum = 0;
	int minVal = 4000;
	int maxVal = -4000;
	for (int i = 0; i < num; ++i)
	{
		cin >> numbers[i];
		sum += numbers[i];
		minVal = minVal > numbers[i] ? numbers[i] : minVal;
		maxVal = maxVal < numbers[i] ? numbers[i] : maxVal;

		sData temp;
		temp.num = numbers[i];
		temp.count = 0;
		numberCount[numbers[i]]++;
	}

	// Case 1
	cout.precision(0);
	double avg = round(static_cast<double>(sum) / numbers.size());
	cout << static_cast<int>(avg) << '\n';

	// Case 2
	int mid = numbers.size() / 2;
	sort(numbers.begin(), numbers.end());
	cout << numbers[mid] << '\n';

	// Case 3
	map<int, int>::iterator it;
	int minNumber = 4000;
	int secondNumber = 4000;
	int maxCount = 0;
	for (it = numberCount.begin(); it != numberCount.end(); ++it)
	{
		maxCount = maxCount < it->second ? it->second : maxCount;
	}

	int maxNumCount = 0;
	for (it = numberCount.begin(); it != numberCount.end(); ++it)
	{
		if (maxCount == it->second)
		{
			minNumber = minNumber > it->first ? it->first : minNumber;
			secondNumber = (minNumber < it->first) && (it->first < secondNumber) ? it->first : secondNumber;
			maxNumCount++;
		}
	}

	if (maxNumCount > 1)
		cout << secondNumber << '\n';
	else
		cout << minNumber << '\n';

	// Case 4
	cout << maxVal - minVal << '\n';

	return 0;
}