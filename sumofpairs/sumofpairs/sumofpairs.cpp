// sumofpairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;


void findPairs(int arr[], int n, int sum) {

	bool found = false;
	map<int, int> msum;
	for (long long i = 0; i < n; ++i)
	{
		msum[arr[i]] += 1;
	}

	for (long long i = 0; i < n; ++i)
	{
		if ((msum.find(sum - arr[i]) != msum.end()) &&
			(msum[arr[i]] >= 1) &&
			(msum[sum - arr[i]] >= 1)
			)
		{
			found = true;
			if (sum - arr[i] == sum / 2)
			{
				if (msum[arr[i]] <= 1)
					found = false;
			}
			if (found) {
				cout << arr[i] << " " << sum - arr[i] << "\n";
				msum[arr[i]] -= 1;
				msum[sum - arr[i]] -= 1;
			}
		}
	}

	if (!found)
		cout << -1 << endl;
}

int main()
{
	int arr[] = { 4,4,5,5,4,6 };

	findPairs(arr, 6, 10);
	return 0;
}

