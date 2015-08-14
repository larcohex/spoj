#include <iostream>
#include <vector>


using namespace std;


int sum (vector <int> &vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
	}
	return sum;
}


void sort (vector <int> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (vec[j] > vec[j+1])
			{
				int temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}
}


bool allDifferent (vector <int> &vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		if (vec[i] != vec[i + 1])
		{
			return true;
		}
	}
	return false;
}


int main()
{
	while (true)
	{
		int N;
		cin >> N; // N - number of packets
		if (N != -1)
		{
			vector <int> packets; // packets - array of packets
			cin.get();
			for (int i = 0; i < N; ++i)
			{
				int temp; // temp - temporary variable for storing number of candies in one packet
				cin >> temp;
				cin.get();
				packets.push_back (temp);
			}
			if (sum (packets) % packets.size())
			{
				cout << -1 << endl;
			}
			else
			{
				int result = 0;
				int mean = sum (packets) / packets.size();
				sort (packets);
				for (int i = 0, j = packets.size() - 1; allDifferent (packets); ++i)
				{
					while (packets[i] != mean)
					{
						if (packets[j] > mean)
						{
							++packets[i];
							--packets[j];
							++result;
						}
						else
						{
							--j;
						}
					}
				}
				cout << result << endl;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
