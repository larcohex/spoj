#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long T; // T - number of test cases;
	cin >> T;
	cin.get();
	for (long long i = 0; i < T; ++i)
	{
		cin.get();
		long long N; // N - number of packets
		vector <long long> packets; // packets - array of packets
		cin >> N;
		cin.get();
		for (long long j = 0; j < N; ++j)
		{
			long long temp;
			cin >> temp;
			cin.get();
			packets.push_back (temp);
		}
		long long sum = 0;
		for (long long j = 0; j < N; ++j)
		{
			sum = (sum + packets[j]) % N;
		}
		if (sum)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
