#include <iostream>
#include <map>

using namespace std;

map <int, float> table;


int f (float n)
{
	int result = 1;
	float length = 0;
	for (int i = 2; length < n; ++i, ++result)
	{
		if (table[i-1])
		{
			length = table[i-1];
		}
		else
		{
			length = 0;
			for (int j = 2; j <= i; ++j)
			{
				length += 1.0/j;
			}
		}
		table[i-1] = length;
	}
	return result-1;
}


int main()
{
	table[0] = 0;
	while (true)
	{
		float n;
		cin >> n;
		if (n)
		{
			cout << f(n) << " card(s)" << endl;
			cin.get();
		}
		else
			break;
	}
}
