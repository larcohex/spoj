#include <iostream>
#include <string>

using namespace std;


void convertToJava (string &line)
{
	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] == '_')
		{
			line[i + 1] -= 32;
			line.erase (i, 1);
		}
	}
}



void convertToC (string &line)
{
	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] > 64 && line[i] < 91)
		{
			line[i] += 32;
			line.insert (i, 1, '_');
		}
	}
}



bool hasUppercase (string line)
{
	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] > 64 && line[i] < 91)
		{
			return true;
		}
	}
	return false;
} 




int main()
{
	string line;
	while (getline (cin, line))
	{
		if (line.find_first_of ('_') != -1)
		{
			if (line[0] == '_' || line[line.size() - 1] == '_')
			{
				cout << "Error!" << endl;
			}
			else
			{
				if (line.find ("__") == -1)
				{
					if (hasUppercase (line))
						cout << "Error!" << endl;
					else
					{
						convertToJava (line);
						cout << line << endl;
					}
				}
				else
					cout << "Error!" << endl;
			}
		}
		else
		{
			if (line[0] > 64 && line[0] < 91)
			{
				cout << "Error!" << endl;
			}
			else
			{
				convertToC (line);
				cout << line << endl;
			}
		}
	}
	return 0;
}
