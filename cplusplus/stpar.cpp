#include <iostream>
#include <list>

using namespace std;


int main()
{
	while (true)
	{
		int n;
		cin >> n;
		if (n)
		{
			list <int> init, exit, side;
			cin.get();
			for (int i = 0; i < n; ++i)
			{
				int temp;
				cin >> temp;
				init.push_back (temp);
			}
			bool order = true;
			while (order && !init.empty())
			{
				if ((exit.empty() && init.front() == 1) || (!exit.empty() && init.front() == exit.front() + 1))
				{
					exit.push_front (init.front());
					init.pop_front();
				}
				else
				{

					if (side.empty() || side.front() > init.front())
					{
						side.push_front(init.front());
						init.pop_front();
					}

					else if (!exit.empty() && side.front() == exit.front() + 1)
					{
						exit.push_front(side.front());
						side.pop_front();
					}

					else
						order = false;


				}
			}


			if (order)
				cout << "yes" << endl;

			else
				cout << "no" << endl;

			cin.get();
		}
		else
			break;
	}
	return 0;
}
