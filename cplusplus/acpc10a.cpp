#include <iostream>

using namespace std;

int main()
{
	while (true)
	{
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		if (a1 == 0 && a2 == 0 && a3 == 0)
		{
			break;
		}
		else
		{
			if (a2 - a1 == a3 - a2)
			{
				int next = a3 + (a3 - a2);
				cout << "AP " << next << endl;
			}
			else if (a2 / a1 == a3 / a2)
			{
				int next = a3 * (a3 / a2);
				cout << "GP " << next << endl;
			}
			cin.get();
		}
	}
	return 0;
}
