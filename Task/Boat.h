#pragma once
#include "Combination.h"
#include <vector>

using namespace std;

struct boat
{
	vector<int> resultW;
	vector<int> resultC;
	vector<int> weight;
	vector<int> coins;
	vector<int> result;
 
	int n = 0;
	int m = 0;
	int sumC = 0;
	int boatW = 0;
	int sumW = 0;
	int maxW = 0;
	int minW = 0;
	int minWP = 0;
	int maxWP = 0;
	int maxC = 0;
	int minC = 0;

	boat(int _n, int _m, int _boatW, int _minWP, int _maxWP, int _minW, int _maxW, int _minC, int _maxC);
	bool start();
	bool print();
};
