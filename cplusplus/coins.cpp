#include <iostream>
#include <map>


using namespace std;


map <int, long long> table;


long long optimize (long long n)
{
	if (!n)
	{
		return 0;
	}
	else
	{
		long long result = table[n];
		if (result)
		{
			return result;
		}
		else
		{
			long long temp = optimize (n/2) + optimize (n/3) + optimize (n/4);
			if (temp > n)
			{
				table[n] = temp;
				return temp;
			}
			else
			{
				table[n] = n;
				return n;
			}
		}
	}
}



int main()
{
	long long n; // n - coin

	while (cin >> n)
	{
		cout << optimize (n) << endl;
	}
	return 0;
}
