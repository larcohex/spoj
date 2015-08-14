#include <iostream>

using namespace std;


int pow (int base, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; ++i)
	{
		result *= base;
	}
	return result;
}


int convert (string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		result += (str[i] - 48) * pow (10, str.size() - 1 - i);
	}
	return result;
}



int main()
{
	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		cin.get();
		string line;
		getline (cin, line);
		string first, second, third;
		int j;
		for (j = 0; line[j] != ' '; ++j)
		{
			first.push_back (line[j]);
		}
		j += 3;
		for (; line[j] != ' '; ++j)
		{
			second.push_back (line[j]);
		}
		j += 3;
		for (; j < line.size(); ++j)
		{
			third.push_back (line[j]);
		}
		if (first.find ("machula") != -1)
		{
			cout << convert (third) - convert (second) << " + " << second << " = " << third << endl;
		}
		else if (second.find ("machula") != -1)
		{
			cout << first << " + " << convert (third) - convert (first) << " = " << third << endl;
		}
		else if (third.find ("machula") != -1)
		{
			cout << first << " + " << second << " = " << convert (first) + convert (second) << endl;
		}
		else
		{
			cout << first << " + " << second << " = " << third << endl;
		}
	}
}
