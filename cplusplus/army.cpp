#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		cin.get();


		int ng, nm;
		cin >> ng >> nm;
		if (ng || nm)
		{
			vector <int> godz, mgodz;
			if (ng > 0)
			{
				cin.get();
				for (int j = 0; j < ng; ++j)
				{
					int temp;
					cin >> temp;
					godz.push_back (temp);
				}
			}
			if (nm > 0)
			{
				cin.get();
				for (int j = 0; j < nm; ++j)
				{
					int temp;
					cin >> temp;
					mgodz.push_back (temp);
				}
			}
			int gmax = 0, mgmax = 0;
			for (int j = 0; j < ng; ++j)
			{
				if (godz[j] > gmax)
					gmax = godz[j];
			}
			for (int j = 0; j < nm; ++j)
			{
				if (mgodz[j] > mgmax)
					mgmax = mgodz[j];
			}

			if (gmax < mgmax)
				cout << "MechaGodzilla" << endl;

			else
				cout << "Godzilla" << endl;
		}

		else
			cout << "uncertain" << endl;

		cin.get();

	}
	return 0;
}
