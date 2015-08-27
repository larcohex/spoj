#include <iostream>
#include <vector>

using namespace std;


int gcd (int a, int b)
{
	while (b)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}


int phi (int n)
{
	int result = n;
	for (int i = 2; i*i <= n; ++i)
	{
		if (!(n % i))
		{
			while (!(n % i))
				n /= i;

			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;

	return result;
}


void find (long diff, long denom)
{
	long temp = 0;
	long i;
	for (i = 1; i < denom && temp < diff; ++i)
	{
		if (gcd (i, denom) == 1)
			++temp;
	}
	--i;
	cout << i << "/" << denom << endl;
}


void f (long n)
{
	if (n == 1)
		cout << "0/1" << endl;
	else if (n == 2)
		cout << "1/1" << endl;
	else
	{
		long sum = 1;
		long checkpoint;
		long i;
		for (i = 1; sum < n; ++i)
		{
			checkpoint = sum;
			sum += phi (i);
		}
		--i;
		long diff = n - checkpoint;
		find (diff, i);
	}
}


int main()
{
	long input;
	while (true)
	{
		cin >> input;
		if (!input)
			break;
		f (input);
	}
}
