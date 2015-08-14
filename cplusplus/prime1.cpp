#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int t;
	int size = sqrt (1000000000);
	unsigned int i, j, k;
	int a[size];
	for (i = 0; i < size; ++i)
	{
		a[i] = i + 2;
	}
	for (i = 2; i <= sqrt (size); ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (a[j] % i == 0 && a[j] != 0)
			{
				break;
			}
		}
		for (; j < size; j = j + i)
		{
			if (a[j] != i)
			{
				a[j] = 0;
			}
		}
	}
	vector <int> primes;
	for (i = 0; i < size; ++i)
	{
		if (a[i] != 0)
		{
			primes.push_back (a[i]);
		}
	}
	cin >> t;
	cin.get();
	for (i = 0; i < t; ++i)
	{
		int m, n;
		cin >> m >> n;
		if (n - m <= 100000 && m <= n && 1 <= m && n <= 1000000000)
		{
			for (j = m; j <= n ; ++j)
			{
				for (k = 0; k < primes.size(); ++k)
				{
					if (primes[k] > sqrt(j))
					{
						if (j != 1)
						{
							cout << j << endl;
						}
						break;
					}
					if (k == primes.size()-1)
					{
						if (j % primes[k])
						{
							cout << j << endl;
						}
					}
					else
					{
						if (!(j % primes[k]))
						{
							break;
						}
					}
				}
			}
		}
		cout << endl;
		cin.get();
	}
	return 0;
}

