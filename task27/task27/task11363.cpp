#include "task27.h"

void task11363()
{
	int N = 0;
	cin >> N;
	int a = 0;
	int b = 0;
	int max = 0;
	int min = 0;
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if ((a - b) > 0)
		{
			max = a;
			min = b;
		}
		else
		{
			max = b;
			min = a;
		}
		int r = max - min;

	}
}