#include <iostream>
#include <cmath>

using namespace std; 

int main()
{
	int t; // t - number of test cases
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		int n; // n - input number
		cin >> n;
		int row = ((sqrt (8*n + 1) - 1) / 2);
		int start = (int)((row * row) / 2.0 + row / 2.0);
		if (n == 1)
		{
			int dif = n - start;
			if (row % 2)
				cout << "TERM " << n << " IS " << row - dif << "/" << 1 + dif << endl;

			else
				cout << "TERM " << n << " IS " << 1 + dif << "/" << row - dif << endl;
		}

		else if (n == start)
		{
			start = (int)(((row - 1) * (row - 1)) / 2.0 + (row - 1) / 2.0);
			int dif = n - start - 1;
			if (row % 2)
				cout << "TERM " << n << " IS " << row - dif << "/" << 1 + dif << endl;

			else
				cout << "TERM " << n << " IS " << 1 + dif << "/" << row - dif << endl;
		}

		else
		{
			++row;
			int dif = n - start - 1;
			if (row % 2)
				cout << "TERM " << n << " IS " << row - dif << "/" << 1 + dif << endl;

			else
				cout << "TERM " << n << " IS " << 1 + dif << "/" << row - dif << endl;
		}

		cin.get();
	}
	return 0;
}
