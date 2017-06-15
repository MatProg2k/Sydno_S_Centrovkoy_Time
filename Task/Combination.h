#pragma once
#include <vector>
using namespace std;

struct combi
{
	int m;
	int n;
	int resSize;

	vector<vector<int>> result;
	combi(int, int);

	bool start();
	int fact(int);
};