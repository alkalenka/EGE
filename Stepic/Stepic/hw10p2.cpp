#include "hw10p2.h"
#include <iostream>

using namespace std;

namespace hw10p2
{
	/*
	�� ���������� ������������ ����� �������� k ������. ������ ������� ����� � ������ ������� ���������� m ����� ����������.
	�� ����� ���������� ����� ������� ��������� � ����� ������ n ������?
	���� ��� ����������� �����: k, m, n, �� ����������� 30000.
	���������� ������� ������������ ����� � ����������� �����, �� ������� ����� ��������� ��� �������.
	*/
	void task1()
	{
		int amountOfCats;
		int time;
		int panCapacity;
		cin >> panCapacity >> time >> amountOfCats;

		cout << (amountOfCats / panCapacity) * 2 * time + (amountOfCats % panCapacity) * 2 * time;
	}
}