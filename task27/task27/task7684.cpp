#include "task27.h"
#include "usefulThings.h"

void task7684()
{
	int number = 0;
	cin >> number;

	int value = 0;
	int max1 = 0;
	int max2 = 0;
	int maxOdd = -1;

	bool flagOddExists = false;

	for (int i = 0; i < number; ++i)
	{
		cin >> value;

		renewMax(max1, max2, value);

		if (value % 2 == 1)
		{
			flagOddExists = true;
			
			if (maxOdd < 0)
			{
				maxOdd = value;
			}
			else if (value > maxOdd)
			{
				maxOdd = value;
			}
		}
	}

	int controlValue = -1;

	cin >> controlValue;

	int calculatedControlValue = -1;
	
	if (!flagOddExists)
	{
		calculatedControlValue = -1;
	}
	else if (max1 % 2 == 0 && max2 % 2 == 0)
	{
		if (max1 > max2)
		{
			calculatedControlValue = max1;
		}
		else
		{
			calculatedControlValue = max2;
		}

		calculatedControlValue += maxOdd;

	}
	else
	{
		calculatedControlValue = max1 + max2;
	}
}