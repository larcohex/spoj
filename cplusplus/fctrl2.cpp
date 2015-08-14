#include <iostream>
#include <vector>
using namespace std;
vector <int> mult (vector <int> &n1, vector <int> &n2)
{
	unsigned int i, j;
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
vector <int> fact (int n)
{
	vector <int> result;
	result.push_back (1);
	for (unsigned int i = 2; i <= n; ++i)
	{
		vector <int> temp;
		if (i < 10)
		{
			temp.push_back (i);
		}
		else
		{
			temp.push_back (i/10);
			temp.push_back (i%10);
		}
		result = mult (result, temp);
	}
	return result;
}
int main()
{
	int t;
	cin >> t;
	cin.get();
	for (unsigned int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cin.get();
		vector <int> result = fact (n);
		for (unsigned int j = 0; j < result.size(); ++j)
		{
			cout << result[j];
		}
		cout << endl;
	}
	return 0;
}
