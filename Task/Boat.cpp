#include "stdafx.h"
#include "Combination.h"
#include "Boat.h"
#include <iostream>

using namespace std;

boat::boat(int _n, int _m, int _boatW, int _minWP, int _maxWP, int _minW, int _maxW, int _minC, int _maxC)
{
	n = _n;
	m = _m;
	boatW = _boatW;
	minW = _minW;
	maxW = _maxW;
	minWP = _minWP;
	minWP = _maxWP;
	minC = _minC;
	maxC = _maxC;

	for (int i = 0; i < n; i++)
	{
		weight.push_back(rand() % (maxW - minW) + minW);
		coins.push_back(rand() % (maxC - minC) + minC);
	}
}

bool boat::start()
{
	vector<vector<int>> temp;
	for (int i = 0; i < pow(2, n); i++)
	{
		vector<int> ins;
		int maska = i;
		for (int j = 0; j < n; j++)
		{
			if (maska & 0x1)
				ins.push_back(j);
			maska = maska >> 1;
		}
		if (ins.size() == m)
			temp.push_back(ins);
	}

	for (int i = 0; i < temp.size(); i++)
	{
		bool flag = true;
		vector<int> tempC;
		vector<int> tempW;
		int tW = 0,
			tC = 0;
		for (int j = 0; j < temp[i].size(); j++)
		{
			if ((weight[temp[i][j]] < minWP) || (weight[temp[i][j]] > maxWP))
			{
				flag = false;
			}

			tW += weight[temp[i][j]];
			tC += coins[temp[i][j]];
			tempC.push_back(coins[temp[i][j]]);
			tempW.push_back(weight[temp[i][j]]);
		}

		if (tC > sumC && boatW >= tW && flag)
		{
			result.clear();
			resultC.clear();
			resultW.clear();
			sumC = tC;
			sumW = tW;
			result.insert(result.begin(), temp[i].begin(), temp[i].end());
			resultC.insert(resultC.begin(), tempC.begin(), tempC.end());
			resultW.insert(resultW.begin(), tempW.begin(), tempW.end());
		}
	}
	return true;
}

bool boat::print()
{
	cout << "Всего контейнров: " << n
		<< "\nМест на судне: " << m
		<< "\nМакс. вместимость: " << boatW
		<< "\nПолученная стоимость: " << sumC
		<< "\nПолученный вес: " << sumW
		<< "\n";
	cout << "Вес:	" << "Цена	\n";
	for (int i = 0; i < n; i++)
	{
		cout << weight[i] << "	" << coins[i] << "\n";
	}

	cout << "Вектор\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	cout << "\nРезультат цен\n";
	for (int i = 0; i < resultC.size(); i++)
	{
		cout << resultC[i] << " ";
	}

	cout << "\nРезультат весов\n";
	for (int i = 0; i < resultW.size(); i++)
	{
		cout << resultW[i] << " ";
	}

	return true;
}