#include <iostream>
#include <vector>

using namespace std;


void merge (vector <int> &v, int begin, int end)
{
	int middle = (begin + end) / 2;
	vector <int> sorted;
	int i, j;
	for (i = begin, j = middle + 1; i <= middle && j <= end;)
	{
		if (v[i] < v[j])
		{
			sorted.push_back (v[i]);
			++i;
		}
		else
		{
			sorted.push_back (v[j]);
			++j;
		}
	}
	while (i <= middle)
	{
		sorted.push_back (v[i]);
		++i;
	}
	while (j <= end)
	{
		sorted.push_back (v[j]);
		++j;
	}
	for (i = begin; i <= end; ++i)
	{
		v[i] = sorted [i-begin];
	}
}


void sort (vector <int> &v, int begin, int end)
{
	if (end > begin)
	{
		int middle = (begin + end) / 2;
		sort (v, begin, middle);
		sort (v, middle + 1, end);
		merge (v, begin, end);
	}
}


int print (int t, vector <int> &v)
{
	int i;
	int result = t;
	for (i = 0; i < v.size(); ++i)
	{
		if (result <= 0)
			return i;
		else
			result -= v[v.size()-1-i];
	}
	if (result <= 0)
		return i;
	else
		return 0;
}

int main()
{
	int t;
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		int task, nfr;
		cin >> task >> nfr;
		cin.get();
		vector <int> stamps;
		for (int j = 0; j < nfr; ++j)
		{
			int temp;
			cin >> temp;
			stamps.push_back (temp);
		}
		sort (stamps, 0, nfr-1);
		int result = print (task, stamps);
		cout << "Scenario #" << i+1 << ":" << endl;
		if (result)
			cout << result << endl;
		else
			cout << "impossible" << endl;
		if (i < t)
			cout << endl;
		cin.get();
	}
	return 0;
}
