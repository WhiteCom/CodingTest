#include <iostream>

using namespace std;

// ( 설명 )
// 티셔츠는 같은 사이즈의 T장 묶음으로만 주문할 수 있다. 
// 펜은 한 종류로 P자루씩 묶음으로 주문하거나 한 자루씩 주문할 수 있다. 
// 참가자들에게 티셔츠 1장, 펜 1자루가 포함된 웰컴 키트를 나눠줌.

int main()
{
	//
	// Input
	//
	int userCount;
	cin >> userCount;

	// Size : S, M, L, XL, XXL, XXXL => 6개
	int clothSize[6] = { 0, };

	for (int i = 0; i < 6; ++i)
	{
		cin >> clothSize[i];
	}

	int T, P;
	cin >> T >> P;

	//
	// Calculate
	//

	int clothCount = 0;
	int multiplePenCount = 0, onePenCount = 0;

	// 1) Cloth
	for (int i = 0; i < 6; ++i)
	{
		// 현재 사이즈에 대한 묶음단위 개수
		int curMultipleCount = 0;
		curMultipleCount = clothSize[i] / T;
		if (clothSize[i] % T == 0)
			clothCount += curMultipleCount;
		else
			clothCount += curMultipleCount + 1;
	}

	// 2) Pen
	multiplePenCount += userCount / P;
	onePenCount += userCount % P;

	cout << clothCount << '\n' << multiplePenCount << " " << onePenCount << '\n';


	return 0;
}