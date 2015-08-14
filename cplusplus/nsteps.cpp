#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.get();
	for (unsigned int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (x - y != 0 && x - y != 2)
		{
			cout << "No Number" << endl;
		}
		else
		{
			if (x == y)
			{
				if (x % 2)
				{
					cout << 2 * x - 1 << endl;
				}
				else
				{
					cout << 2 * x << endl;
				}
			}
			else
			{
				if (x % 2)
				{
					cout << 2 * x - 3 << endl;
				}
				else
				{
					cout << 2 * x - 2 << endl;
				}
			}
		}
	}
	return 0;
}
