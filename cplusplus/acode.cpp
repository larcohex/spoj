#include <iostream>
#include <string>

using namespace std;


bool g (char ch1, char ch2)
{
	if (ch1 > '2')
	{
		return false;
	}
	else if (ch1 == '2')
	{
		if (ch2 > '6')
		{
			return false;
		}
	}
	return true;
}



int main()
{
	string line;
	while (true)
	{
		getline (cin, line);

		if (line == "0")
			break;

		else
		{
			long long temp1 = 1;
			long long temp2 = 1;
			for (int i = 0; i < line.size() - 1; ++i)
			{
				if (line[i+1] == '0')
				{
					int temp = temp2 - (temp2 - temp1);
					temp1 = temp2;
					temp2 = temp;
				}
				else if (line[i] == '0')
				{
					temp1 = temp2;
				}
				else if (g (line[i], line[i+1]))
				{
					int temp = temp1 + temp2;
					temp1 = temp2;
					temp2 = temp;
				}
				else
				{
					temp1 = temp2;
				}
			}
			cout << temp2 << endl;
		}
	}
	return 0;
}
