#include <iostream>

using namespace std;

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


int main()
{
	int input;
	cin >> input;
	cout << phi(input) << endl;
	return 0;
}
