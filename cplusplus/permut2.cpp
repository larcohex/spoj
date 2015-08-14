#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void merge (vector < pair <int, int> > &v, int begin, int end)
{
	int middle = (begin + end) / 2;
	int i, j;
	vector < pair <int, int> > sorted;
	for (i = begin, j = middle + 1; (i <= middle) && (j <= end);)
	{
		if (v[i].first < v[j].first)
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
		v[i] = sorted[i - begin];
	}
}


void sort (vector < pair <int, int> > &top, int begin, int end)
{
	if (end > begin)
	{
		int middle = (begin + end) / 2;
		sort (top, begin, middle);
		sort (top, middle + 1, end);
		merge (top, begin, end);
	}
}


int main()
{
	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		else
		{
			cin.get();
			vector < pair <int, int> > arr; 
			for (int i = 1; i <= n; ++i)
			{
				int temp;
				cin >> temp;
				pair <int, int> p (temp, i);
				arr.push_back (p);
			}
			vector < pair <int, int> > arr2 (arr);
			sort (arr2, 0, n-1);

			bool ambiguous = true;
			for (int i = 0; i < n; ++i)
			{
				if (arr[i].first != arr2[i].second)
				{
					ambiguous = false;
					break;
				}
			}

			if (ambiguous)
				cout << "ambiguous" << endl;

			else
				cout << "not ambiguous" << endl;

			cin.get();
		}
	}
}
