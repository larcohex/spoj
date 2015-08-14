#include <iostream>

using namespace std;

int main()
{
	unsigned long long n;
	cin >> n;
	if (n < 2)
		cout << "TAK" << endl;
	else
	{
		if (n & (n - 1))
			cout << "NIE" << endl;
		else
			cout << "TAK" << endl;
	}
	return 0;
}
