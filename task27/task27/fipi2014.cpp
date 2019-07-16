#include "task27.h"

void fipi2014()
{
	int n3 = 0;
	int n7 = 0;
	int n21 = 0;
	int x = 0;
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if ((x % 3 == 0) && (x % 7 != 0))
		{
			++n3;
		}
		if ((x % 3 != 0) && (x % 7 == 0))
		{
			++n7;
		}
		if (x % 21 == 0)
		{
			++n21;
		}
	}

}