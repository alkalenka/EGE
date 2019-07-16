#include "task27.h"

void task11363()
{
	int amount = 0;
	cin >> amount;
	int sumOfMax = 0;
	int minSubtractNotDividedByThree = 10000;
	for (int i = 0; i < amount; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		sumOfMax += a > b ? a : b;
		int currentSubtract = abs(a - b);
		if (currentSubtract < minSubtractNotDividedByThree)
		{
			minSubtractNotDividedByThree = currentSubtract;
		}
	}
	if (sumOfMax % 3 != 0)
	{
		cout << sumOfMax;
	}
	else
	{
		if (minSubtractNotDividedByThree < 10000)
		{
			sumOfMax -= minSubtractNotDividedByThree;
			cout << sumOfMax;
		}
		else
		{
			cout << 0;
		}
	}
}