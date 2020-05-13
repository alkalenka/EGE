#include "hw9p2.h"
#include <iostream>

using namespace std;

namespace hw9p2
{
	void task1()
	{
		// input initial data
		int const n = 4;
		int numbers[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> numbers[i];
		}

		// search max last digit
		int maxLastDigit = -1;
		for (int i = 0; i < n; ++i)
		{
			int currentLastDigit = numbers[i] % 10;
			if (currentLastDigit > maxLastDigit)
			{
				maxLastDigit = currentLastDigit;
			}
		}

		// search max number with this digit
		int maxNumber = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			if (numbers[i] % 10 == maxLastDigit)
			{
				if (numbers[i] > maxNumber)
				{
					maxNumber = numbers[i];
				}
			}
		}

		// result output
		cout << maxNumber;
	}

	/*
	ƒаны четыре целых положительных числа, найдите минимальное нечетное число (гарантируетс€, что нечетные числа есть).
	«атем уменьшите все нечетные числа, которые больше найденного значени€,
	на найденное значение и выведите все четыре числа в том же пор€дке, каждое число в новой строчке.
	*/
	void task2()
	{
		// get initial data
		int const n = 4;
		int numbers[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> numbers[i];
		}

		// find min odd number
		int minOddNumber = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			if (numbers[i] % 2 == 1 && numbers[i] < minOddNumber)
			{
				minOddNumber = numbers[i];
			}
		}

		// subtruct min odd number from odd numbers
		for (int i = 0; i < n; ++i)
		{
			if (numbers[i] % 2 == 1 && numbers[i] > minOddNumber)
			{
				numbers[i] -= minOddNumber;
			}
		}

		// result output
		for (int i = 0; i < n; ++i)
		{
			cout << numbers[i] << endl;
		}
	}

	/*
	ѕет€ живет в городе ѕ, его друг ¬ан€ живет в городе ¬.
	ƒвое друзей не виделись весь карантин, как только вирус был побежден, они сели на велосипеды и поехали друг на встречу другу.
	ќпределите, через сколько секунд они встрет€тс€, если на вход мы получаем
	три целых положительных числа: рассто€ние между городами ѕ и ¬ в метрах, скорость ѕети (м/c) и скорость ¬ани (м/c).
	*/
	void task3()
	{
		int petyaSpeed;
		int vanyaSpeed;
		int distance;
		cin >> distance >> petyaSpeed >> vanyaSpeed;

		int time = 0;
		while ((petyaSpeed * time + vanyaSpeed * time) < distance)
		{
			++time;
		}

		cout << time;
	}
}