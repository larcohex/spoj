#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int pow (int base, int exp)
{
	int result = 1;
	for (unsigned int i = 0; i < exp; ++i)
	{
		result *= base;
	}
	return result;
}



int reverse (string n)
{
	int result = 0;
	for (unsigned int i = 0; i < n.size(); ++i)
	{
		result += (n[i] - 48) * pow (10, i);
	}
	return result;
}


string convert (int n)
{
	string s;
	stringstream out;
	out << n;
	s = out.str();
	return s;
}




int main()
{
	int N;
	cin >> N;
	cin.get();
	for (unsigned int i = 0; i < N; ++i)
	{
		string n1, n2;
		cin >> n1;
		cin.get();
		cin >> n2;
		cout << reverse (convert (reverse (n1) + reverse (n2))) << endl;
	}
	return 0;
}
