#include "task27.h"

void fipi2018()
{
	int n2 = 0;
	int n13 = 0;
	int n26 = 0;
	int N = 0;
	cin >> N;
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if ((x % 2 == 0) && (x % 13 != 0))
		{
			++n2;
		}
		if ((x % 2 != 0) && (x % 13 == 0))
		{
			++n13;
		}
		if (x % 26 == 0)
		{
			++n26;
		}
	}
	int n = N - n2 - n13 - n26;
	int count = n2 * n13 + n2 * n26 + n26 * n13 + n * n26;
	cout << count;
}