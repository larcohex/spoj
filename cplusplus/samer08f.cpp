#include <iostream>

using namespace std;

int main()
{
	while (1)
	{
		int N; //N - size of square
		cin >> N;
		if (N)
		{
			cin.get();
			int result = 0;
			for (int i = 1; i <= N; ++i)
			{
				result += i*i;
			}
			cout << result << endl;
		}
		else
			break;
	}
}
