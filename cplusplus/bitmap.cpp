#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;



void bfs (vector < vector <int> > &map, list < pair <int, int> > &queue, int rows, int cols)
{
	while (!queue.empty())
	{
		pair <int, int> temp = queue.front();
		queue.pop_front();
		int nearxs[4] = {0, -1, 0, 1};
		int nearys[4] = {-1, 0, 1, 0};
		for (int i = 0; i < 4; ++i)
		{
			int x = temp.first + nearxs[i];
			int y = temp.second + nearys[i];
			if (x < rows && x >= 0 && y < cols && y >= 0)
			{
				if (map[x][y] == -1 || map[temp.first][temp.second] + 1 < map[x][y])
				{
					map[x][y] = map[temp.first][temp.second] + 1;
					queue.push_back (make_pair (x, y));
				}
			}
		}
	}
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		list < pair <int, int> > queue;
		int n, m;
		cin >> n >> m;
		vector < vector <char> > bitmap;
		vector < vector <int> > result;
		for (int j = 0; j < n; ++j)
		{
			vector <int> tempv;
			for (int k = 0; k < m; ++k)
			{
				tempv.push_back (-1);
			}
			result.push_back (tempv);
		}
		for (int j = 0; j < n; ++j)
		{
			vector <char> tempv;
			for (int k = 0; k < m; ++k)
			{
				char temp;
				cin >> temp;
				tempv.push_back (temp);
				if (temp == '1')
				{
					queue.push_back (make_pair (j, k));
					result[j][k] = 0;
				}
			}
			bitmap.push_back (tempv);
		}
		bfs (result, queue, n, m);
		for (int j = 0; j < n; ++j)
		{
			cout << result[j][0];
			for (int k = 1; k < m; ++k)
			{
				cout << " " << result[j][k];
			}
			cout << endl;
		}
	}
	return 0;
}
