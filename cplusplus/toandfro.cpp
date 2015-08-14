#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	while (1)
	{
		int col;
		cin >> col;
		if (col)
		{
			int i, j, k;
			string line;
			cin.get();
			cin >> line;
			cin.get();
			vector <string> result;
			for (i = 0, j = 0; j < line.size(); ++i)
			{
				string temp;
				for (k = 0; k < col; ++j, ++k)
				{
					temp.push_back (line[j]);
				}
				result.push_back (temp);
			}
			for (i = 0; i < col; ++i)
			{
				for (j = 0; j < result.size(); ++j)
				{
					if (j % 2)
					{
						cout << result[j][col-1-i];
					}
					else
					{
						cout << result[j][i];
					}
				}
			}
			cout << endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}
