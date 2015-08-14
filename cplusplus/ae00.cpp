#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= sqrt (i); ++j)
		{
			if (!(i % j))
			{
				++result;
			}
		}
	}
	cout << result << endl;
	return 0;
}
