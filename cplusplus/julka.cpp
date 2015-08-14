#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		int total, dif;
		cin >> total >> dif;
		cin.get();
		int natalia, klaudia;
		natalia = (total - dif) / 2;
		klaudia = (total + dif) / 2;
		cout << klaudia << "\n" << natalia << "\n" << endl;
	}
	return 0;
}
