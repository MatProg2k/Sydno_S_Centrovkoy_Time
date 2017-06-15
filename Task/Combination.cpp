#include "stdafx.h"
#include "Combination.h"

combi::combi(int _n, int _m)
{
	m = _m;
	n = _n;
	resSize = fact(n) / (fact(n - m) * fact(m));
}

bool combi::start()
{
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
			result.push_back(ins);
	}
	return true;
}

int  combi::fact(int x)
{
	if (x == 1 | x == 0)
	{
		return 1;
	}
	return fact(x - 1) * x;
}