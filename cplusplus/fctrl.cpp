#include <iostream>

using namespace std;


int power (int base, int exp)
{
	int result = 1;
	for (unsigned int i = 0; i < exp; ++i)
	{
		result *= base;
	}
	return result;
}


int count (int n)
{
	int result = 0;
	for (unsigned int i = 1; power (5, i) < n; ++i)
	{
		result += (n / (power (5, i)));
	}
	return result;
}



int main()
{
	int N;
	cin >> N;
	cin.get();
	for (unsigned int i = 0; i < N; ++i)
	{
		int n;
		cin >> n;
		cin.get();
		cout << count (n) << endl;
	}
	return 0;
}
