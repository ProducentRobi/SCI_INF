#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

void alg::see()
{
	for (int i = 0; i < 100; i++)
	{
		cout << exercise[i] << " ";
	}
}

void alg::random()
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		exercise.push_back(rand() % 1000);
	}
}

void alg::bubbles()
{
	for (int i = 0; i < 100; i++)
	{
		for (int k = 1; k < 99; k++)
		{
			if (exercise[k] > exercise[k + 1])
			{
				swap(exercise[k], exercise[k + 1]);
			}
		}
	}
}

void alg::insert()
{
	int x, k;
	for (int i = 1; i < 100; i++)
	{
		x = exercise[i];
		k = i - 1;
		while (k >= 0 && exercise[k] > x)
		{
			exercise[k + 1] = exercise[k];
			k--;
		}
		exercise[k + 1] = x;
	}
}