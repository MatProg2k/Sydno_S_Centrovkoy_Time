#include "stdafx.h"
#include "Combination.h"
#include "Boat.h"
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::ofstream file("Res.txt", std::ios::app);
	for (int i = 4; i < 11; i++)
	{
		clock_t start = clock();
		boat boat(15, i, 1500, 50, 200, 100, 180, 10, 150);
		boat.start();
		clock_t stop = clock();
		file << "Количество мест: " << i << ", затраченное время: " << (long)(stop - start) << std::endl;
	}
	file.close();

	system("pause");
	return 0;
}