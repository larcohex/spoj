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
		cout << 192 + (n - 1) * 250 << endl;
		cin.get();
	}
	return 0;
}
