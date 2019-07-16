#include "task27.h"

void fipi2017()
{
	int n = 0;
	cin >> n;
	int x = 0;
	int y = 0;
	int s = 0;
	int r = 10000;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		int t = abs(x - y);
		if ((t % 3 != 0) && (t < r))
		{
			r = t;
		}
		if (x > y)
		{
			s += x;
		}
		else
		{
			s += y;
		}
	}
	if (s % 3 != 0)
	{
		cout << s;
	}
	else
	{
		if (r == 10000)
		{
			cout << 0;
		}
		else
		{
			cout << s - r;
		}
	}
}