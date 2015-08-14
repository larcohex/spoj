#include <iostream>
#include <vector>

using namespace std;


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


int main()
{
	int t; // t - number of test cases
	cin >> t;
	cin.get();
	for (int i = 0; i < t; ++i)
	{
		vector <int> male; // male - hotness levels of men
		vector <int> female; // female - hotness levels of female
		int N; // N - number of participants
		cin >> N;
		cin.get();
		for (int j = 0; j < N; ++j)
		{
			int temp; // temp - temporary for each participant
			cin >> temp;
			male.push_back (temp);
		}
		cin.get();
		for (int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			female.push_back (temp);
		}
		sort (male);
		sort (female);
		int total = 0; //total - sum of hotness bonds
		for (int j = 0; j < N; ++j)
		{
			total += male[j] * female[j];
		}
		cout << total << endl;
	}
	return 0;
}
