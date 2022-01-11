#include <iostream>
#include "alg.h"
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

const int numbers_amount = 10000;

void alg::see()
{
	for (int i = 0; i < numbers_amount; i++)
	{
		cout << vec[i] << " ";
	}
}

void alg::random()
{
	srand(time(NULL));
	for (int i = 0; i < numbers_amount; i++)
	{
		vec.push_back(rand() % numbers_amount);
	}
}

void alg::bubbles()
{
	for (int i = 0; i < numbers_amount - 1; i++)
	{
		for (int k = 0; k < numbers_amount - 1; k++)
		{
			if (vec[k] > vec[k + 1])
			{
				swap(vec[k], vec[k + 1]);
			}
		}
	}
}

void alg::insert()
{
	int x, k;
	for (int i = 1; i < numbers_amount; i++)
	{
		x = vec[i];
		k = i - 1;
		while (k >= 0 && vec[k] > x)
		{
			vec[k + 1] = vec[k];
			k--;
		}
		vec[k + 1] = x;
	}
}

void alg::choosing()
{
	{
		int a;

		for (int i = 0; i < vec.size(); i++)
		{
			a = i;

			for (int k = i + 1; k < vec.size(); k++)
			{
				if (vec[k] < vec[a])
				{
					a = k;
				}
			}

			swap(vec[i], vec[a]);
		}
	}
}

void alg::quicksort(int left, int right)
{
	int i = (left + right) / 2;
	int z = vec[i];
	vec[i] = vec[right];
	int k = left;

	for (i = left; i < right; i++)
	{
		if (vec[i] < z)
		{
			swap(vec[i], vec[k]);
			k = k + 1;
		}
	}

	vec[right] = vec[k];
	vec[k] = z;

	if (left < k - 1)
	{
		quicksort(left, k - 1);
	}

	if (k + 1 < right)
	{
		quicksort(k + 1, right);
	}
}