#include <iostream>
#define PI 3.1415926535

using namespace std;

int main()
{
	while (true)
	{
		float L;
		cin >> L;
		if (L)
		{
			cout.precision (2);
			cout << fixed << (L * L) / (2 * PI) << endl;
		}
		else
			break;
	}
	return 0;
}
