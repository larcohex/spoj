#include <iostream>
#include <vector>

using namespace std;

int main()
{
	while (true)
	{
		int a, d;
		cin >> a >> d;
		if (!a && !d)
			break;
		else
		{
			long att = -1, def1 = -1, def2 = -1;
			for (int i = 0; i < a; ++i)
			{
				long temp;
				cin >> temp;
				if (att == -1 || temp < att)
					att = temp;
			}
			cin.get();
			for (int i = 0; i < d; ++i)
			{
				long temp;
				cin >> temp;
				if (def1 == -1 || temp < def1)
				{
					def2 = def1;
					def1 = temp;
				}
				else if (def2 == -1 || temp < def2)
				{
					def2 = temp;
				}
			}
			if (att < def2)
				cout << "Y" << endl;
			else
				cout << "N" << endl;
			cin.get();
		}
	}
	return 0;
}
