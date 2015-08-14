#include <iostream>
#include <string>
#include <vector>


using namespace std;


vector <int> mult (vector <int> &n1, vector <int> &n2)
{
	int i, j;
	int s1 = n1.size();
	int s2 = n2.size();
	if (s2 == 1)
	{
		vector <int> result;
		++s1;
		for (i = 0; i < s1; ++i)
		{
			result.push_back (0);
		}
		for (i = 0; i < s1 - 1; ++i)
		{
			int temp = n1[s1 - 2 - i] * n2[0];
			result[s1 - 1 - i] += temp;
			result[s1 - 2 - i] += result[s1 - 1 - i] / 10;
			result[s1 - 1 - i] %= 10;
		}
		if (result[0] == 0)
		{
			result.erase (result.begin());
		}
		return result;
	}
	else
	{
		vector <vector <int> > result;
		for (i = 0; i < s2; ++i)
		{
			vector <int> temp;
			for (j = 0; j < s1 + s2; ++j)
			{
				temp.push_back (0);
			}
			result.push_back (temp);
			for (j = 0; j < s1; ++j)
			{
				int temp = n1[s1 - 1 - j] * n2[s2 - 1 - i];
				result[i][s2 + s1 - 1 - j - i] += temp;
				result[i][s2 + s1 - 2 - j - i] += result[i][s2 + s1 - 1 - j - i] / 10;
				result[i][s2 + s1 - 1 - j - i] %= 10;
			}
		}
		vector <int> compResult;
		for (i = 0; i < s1 + s2; ++i)
		{
			compResult.push_back (0);
		}
		for (i = 0; i < result.size(); ++i)
		{
			for (j = 0; j < s1 + s2; ++j)
			{
				compResult[s1 + s2 - 1 - j] += result[i][s1 + s2 - 1 - j];
				if (j != s1 + s2 - 1)
				{
					compResult[s1 + s2 - 2 - j] += compResult[s1 + s2 - 1 - j] / 10;
				}
				compResult[s1 + s2 - 1 - j] %= 10;
			}
		}
		if (compResult[0] == 0)
		{
			compResult.erase (compResult.begin());
		}
		return compResult;
	}
}



vector <int> subtr (vector <int> &n1, vector <int> &n2)
{
	int i, j;
	vector <int> result;
	int s1 = n1.size();
	int s2 = n2.size();
	bool spaces = false;
	if (s1 == s2)
	{
		spaces = true;
	}
	bool temp = spaces;
	if (s1 > s2)
	{
		for (i = 0; i < s1 - s2; ++i)
		{
			n2.insert (n2.begin(), 0);
		}
	}
	s2 = n2.size();
	for (i = 0; i < s1; ++i)
	{
		result.push_back (0);
	}
	for (i = 0; i < s1; ++i)
	{
		int temp = n1[s1 - 1 - i] - n2[s2 - 1 - i];
		result[s1 - 1 - i] += temp;
	}
	for (i = s1 - 1; i > 0; --i)
	{
        	if (result[i] < 0)
        	{
			for (j = i; result[j] <= 0; --j)
			{
			}
			for (; j < i; ++j)
			{
				result[j + 1] += 10;
				--result[j];
			}
		}
	}
	while (!result.empty() && result[0] == 0)
	{
		result.erase (result.begin());
	}
	return result;
}


vector <int> convert (string &str)
{
	vector <int> result;
	for (int i = 0; i < str.size(); ++i)
	{
		result.push_back (str[i] - 48);
	}
	return result;
}


int main()
{
	string n;
	while (getline (cin, n))
	{
		if (n == "1")
		{
			cout << 1 << endl;
		}
		else
		{
			vector <int> temp;
			temp.push_back (2);
			vector <int> n2 = convert (n);
			vector <int> temp2 = mult (n2, temp);
			vector <int> result = subtr (temp2, temp);
			for (int i = 0; i < result.size(); ++i)
			{
				cout << result[i];
			}
			cout << endl;
			temp.clear();
			n2.clear();
			temp2.clear();
			result.clear();
		}
	}
	return 0;
}
