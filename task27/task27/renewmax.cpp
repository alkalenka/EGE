#include "usefulThings.h"

void renewMax(int& max1, int& max2, int value)
{
	if (max1 <= 0 || max2 <= 0)
	{
		if (max1 == 0)
		{
			max1 = value;
		}
		else
		{
			max2 = value;
		}
	}
	else if (value > max1 || value > max2)
	{
		if (max2 > max1)
		{
			max1 = value;
		}
		else
		{
			max2 = value;
		}
	}
}