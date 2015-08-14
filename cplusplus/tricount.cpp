#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		long long n;
		cin >> n;
		cout << n * (n+2) * (2*n+1) / 8 << endl;
	}
	return 0;
}
