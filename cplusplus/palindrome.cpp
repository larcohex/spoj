#include <iostream>
#include <string>

using namespace std;

int main()
{
	unsigned int i, j;
	int t;
	cin >> t;
	cin.get();
	for (i = 0; i < t; ++i)
	{
		string a;
		getline (cin, a);
		if (a.size() != 1)
		{
			int size = a.size();
			int center = size / 2;
			string str1;
			str1.append (a, 0, center);
			string str2;
			for (j = 0; j < center; ++j)
			{
				str2.push_back (a[size - 1 - j]);
			}
			if (str2 >= str1)
			{
				for (j = center + 1; j < size; ++j)
				{
					a[j] = '0';
				}
				for (j = 0; j < center + 1; ++j)
				{
					++a[center - j];
					if (a[center - j] > '9')
					{
						a[center - j] = '0';
						if (j != center)
						{
							++a[center - 1 - j];
							if (a[center - 1 - j] <= '9')
							{
								break;
							}
						}
						else
						{
							a.insert(a.begin(), '1');
						}
					}
					else
					{
						break;
					}
				}
			}
			string result = a;
			size = result.size();
			center = size / 2;
			for (j = 0; j < center; ++j)
			{
				result[size - 1 - j] = result[j];
			}
			if (result <= a)
			{
				++result[center];
				if (!(size % 2))
				{
					++result[center-1];
				}
			}
			cout << result << endl;
		}
		else
		{
			++a[0];
			cout << a << endl;
		}
	}
	return 0;
}
