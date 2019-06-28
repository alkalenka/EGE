#include "usefulThings.h"

void firstTwoMaxFromSequence()
{
	int max1 = -1001;
	int max2 = -1001;
	int k = 0;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> k;
		if (k > max1)
		{
			max2 = max1;
			max1 = k;
		}
		else if (k > max2 && k != max1)
		{
			max2 = k;
		}
	}
	cout << "First max = " << max1 << endl << "Second max = " << max2 << endl;
}
