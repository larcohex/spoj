#include <iostream>
#include <vector>

using namespace std;

void add (vector <int> *n1, vector <int> *n2)
{
	unsigned int i, j;
	vector <int> result;
	int s1 = n1->size();
	int s2 = n2->size();
	int size1 = s1;
	int size2 = s2;
	if (s1 > s2)
	{
		for (i = 0; i <= s1 - s2; ++i)
		{
			n2->insert (n2->begin(), 0);
		}
		n1->insert (n1->begin(), 0);
	}
	else if (s2 > s1)
	{
		for (i = 0; i <= s2 - s1; ++i)
		{
			n1->insert (n1->begin(), 0);
		}
		n2->insert (n2->begin(), 0);
	}
	else
	{
		n1->insert (n1->begin(), 0);
		n1->insert (n1->begin(), 0);
		n2->insert (n2->begin(), 0);
		n2->insert (n2->begin(), 0);
	}
	s1 = s2 = n2->size();
	for (i = 0; i < s1; ++i)
	{
		result.push_back (0);
	}
	for (i = 0; i < s1 - 1; ++i)
	{
		int temp = (*n1)[s1 - 1 - i] + (*n2)[s2 - 1 - i];
		result[s1 - 2 - i] += (result[s1 - 1 - i] + temp) / 10;
		result[s1 - 1 - i] += temp % 10;
		result[s1 - 1 - i] %= 10;
	}
	if (result[0] == 0 && size1 >= size2)
	{
		n1->erase (n1->begin());
		n2->erase (n2->begin());
		result.erase (result.begin());
		--s1;
		--s2;
	}
	bool spaces = true;
	for (i = 0; i < s1; ++i)
	{
		if ((*n1)[i] == 0 && spaces == true)
		{
			cout << " ";
		}
		else
		{
			cout << (*n1)[i];
			spaces = false;
		}
	}
	cout << endl;
	spaces = true;
	int sp = 0;
	for (i = 0; i < s2; ++i)
	{
		if ((*n2)[i] == 0 && spaces == true)
		{
			++sp;
		}
		else
		{
			if (spaces == true)
			{
				--sp;
				if (sp != -1)
				{
					for (j = 0; j < sp; ++j)
					{
						cout << " ";
					}
				}
				cout << "+" << (*n2)[i];
				spaces = false;
			}
			else
			{
				cout << (*n2)[i];
			}
		}
	}
	cout << endl;
	for (i = 0; i < s1; ++i)
	{
		cout << "-";
	}
	cout << endl;
	spaces = true;
	for (i = 0; i < s1; ++i)
	{
		if (result[i] == 0 && spaces == true)
		{
			cout << " ";
		}
		else
		{
			cout << result[i];
			spaces = false;
		}
	}
	cout << endl;
}



void subtr (vector <int> *n1, vector <int> *n2)
{
	unsigned int i, j;
	vector <int> result;
	int s1 = n1->size();
	int s2 = n2->size();
	bool spaces = false;
	if (s1 == s2)
	{
		spaces = true;
	}
	bool temp = spaces;
	if (s1 > s2)
	{
		for (i = 0; i < s1 - s2; ++i)
		{
			n2->insert (n2->begin(), 0);
		}
	}
	s2 = n2->size();
	for (i = 0; i < s1; ++i)
	{
		result.push_back (0);
	}
	for (i = 0; i < s1; ++i)
	{
		int temp = (*n1)[s1 - 1 - i] - (*n2)[s2 - 1 - i];
		result[s1 - 1 - i] += temp;
	}
	for (i = s1 - 1; i > 0; --i)
	{
		if (result[i] < 0)
		{
			for (j = i; result[j] <= 0; --j)
			{
			}
			for (; j < i; ++j)
			{
				result[j + 1] += 10;
				--result[j];
			}
		}
	}
	for (i = 0; i < s1; ++i)
	{
		if (spaces)
		{
			cout << " ";
			spaces = false;
		}
		cout << (*n1)[i];
	}
	cout << endl;
	spaces = true;
	int sp = 0;
	for (i = 0; i < s2; ++i)
	{
		if ((*n2)[i] == 0 && spaces == true)
		{
			++sp;
		}
		else
		{
			if (spaces == true)
			{
				--sp;
				if (sp != -1)
				{
					for (j = 0; j < sp; ++j)
					{
						cout << " ";
					}
				}
				cout << "-" << (*n2)[i];
				spaces = false;
			}
			else
			{
				cout << (*n2)[i];
			}
		}
	}
	cout << endl;
	if (temp)
	{
		for (i = 0; i < s1 + 1; ++i)
		{
			cout << "-";
		}
	}
	else
	{
		for (i = 0; i < s1; ++i)
		{
			cout << "-";
		}
	}
	cout << endl;
	if (temp)
	{
		cout << " ";
	}
	spaces = true;
	sp = 0;
	for (i = 0; i < s1; ++i)
	{
		if (result[i] == 0 && spaces == true && i != s1 - 1)
		{
			++sp;
		}
		else
		{
			if (spaces == true && i != s1 - 1)
			{
				for (j = 0; j < sp; ++j)
				{
					cout << " ";
				}
				cout << result[i];
				spaces = false;
			}
			else if (spaces == true && i == s1 - 1)
			{
				for (j = 0; j < sp; ++j)
				{
					cout << " ";
				}
				cout << result[i];
			}
			else if (spaces == false)
			{
				cout << result[i];
			}
		}
	}
	cout << endl;
}




void mult (vector <int> *n1, vector <int> *n2)
{
	unsigned int i, j;
	int s1 = n1->size();
	int s2 = n2->size();
	if (s2 == 1)
	{
		vector <int> result;
		n1->insert (n1->begin(), 0);
		++s1;
		for (i = 0; i < s1; ++i)
		{
			result.push_back (0);
		}
		for (i = 0; i < s1 - 1; ++i)
		{
			int temp = (*n1)[s1 - 1 - i] * (*n2)[0];
			result[s1 - 1 -i] += temp;
			result[s1 - 2 - i] += result[s1 - 1 - i] / 10;
			result[s1 - 1 - i] %= 10;
		}
		if (result[0] == 0)
		{
			result.erase (result.begin());
			n1->erase (n1->begin());
			--s1;
		}
		bool spaces = true;
		for (i = 0; i < s1; ++i)
		{
			if (spaces == true && (*n1)[i] == 0)
			{
				cout << " ";
			}
			else
			{
				cout << (*n1)[i];
				spaces = false;
			}
		}
		cout << endl;
		for (i = 0; i < s1 - 2; ++i)
		{
			cout << " ";
		}
		cout << "*";
		cout << (*n2)[0];
		cout << endl;
		for (i = 0; i < result.size(); ++i)
		{
			cout << "-";
		}
		cout << endl;
		for (i = 0; i < result.size(); ++i)
		{
			cout << result[i];
		}
		cout << endl;
	}
	else
	{
		vector < vector <int> > result;
		for (i = 0; i < s2; ++i)
		{
			vector <int> temp;
			for (j = 0; j < s1 + s2; ++j)
			{
				temp.push_back (0);
			}
			result.push_back (temp);
			for (j = 0; j < s1; ++j)
			{
				int temp = (*n1)[s1 - 1 - j] * (*n2)[s2 - 1 - i];
				result[i][s2 + s1 - 1 - j - i] += temp;
				result[i][s2 + s1 - 2 - j - i] += result[i][s2 + s1 - 1 - j - i] / 10;
				result[i][s2 + s1 - 1 - j - i] %= 10;
			}
		}
		vector <int> compResult;
		for (i = 0; i < s1 + s2; ++i)
		{
			compResult.push_back (0);
		}
		for (i = 0; i < result.size(); ++i)
		{
			for (j = 0; j < s1 + s2; ++j)
			{
				compResult[s1 + s2 - 1 - j] += result[i][s1 + s2 - 1 - j];
				if (j != s1 + s2 - 1)
				{
					compResult[s1 + s2 - 2 - j] += compResult[s1 + s2 - 1 - j] / 10;
				}
				compResult[s1 + s2 - 1 - j] %= 10;
			}
		}
		int resultSize = compResult.size();
		if (compResult[0] == 0)
		{
			compResult.erase (compResult.begin());
			--resultSize;
			for (i = 0; i < result.size(); ++i)
			{
				result[i].erase (result[i].begin());
			}
		}
		if (resultSize == s2)
		{
			for (i = 0; i < s2 - s1 + 1; ++i)
			{
				cout << " ";
			}
			for (i = 0; i < s1; ++i)
			{
				cout << (*n1)[i];
			}
			cout << endl;
			cout << "*";
			for (i = 0; i < s2; ++i)
			{
				cout << (*n2)[i];
			}
			cout << endl;
			for (i = 0; i < s2 + 1; ++i)
			{
				cout << "-";
			}
			cout << endl;
			int counter = 0;
			bool spaces = true;
			for (i = 0; i < result.size(); ++i, ++counter)
			{
				cout << " ";
				for (j = 0; j < resultSize - counter; ++j)
				{
					if (result[i][j] == 0 && spaces == true && j != resultSize - 1 - counter)
					{
						cout << " ";
					}
					else
					{
						if (spaces == true && j == resultSize - 1 - counter)
						{
							cout << result[i][j];
							break;
						}
						else if (spaces == true && j != resultSize - 1 - counter)
						{
							cout << result[i][j];
							spaces = false;
						}
						else if (spaces == false && j != resultSize - 1 - counter)
						{
							cout << result[i][j];
						}
						else
						{
							cout << result[i][j];
							break;
						}
					}
				}
				cout << endl;
				spaces = true;
			}
			cout << " ";
			for (i = 0; i < s2; ++i)
			{
				cout << "-";
			}
			cout << endl;
			cout << " ";
			for (i = 0; i < resultSize; ++i)
			{
				cout << compResult[i];
			}
		}
		else
		{
			for (i = 0; i < resultSize - s1; ++i)
			{
				cout << " ";
			}
			for (i = 0; i < s1; ++i)
			{
				cout << (*n1)[i];
			}
			cout << endl;
			for (i = 0; i < resultSize - s2 - 1; ++i)
			{
				cout << " ";
			}
			cout << "*";
			for (i = 0; i < s2; ++i)
			{
				cout << (*n2)[i];
			}
			cout << endl;
			int zeroSize = 0;
			bool spaces = true;
			for (i = 0; i < result[0].size(); ++i)
			{
				if (spaces == true && result[0][i] == 0)
				{
				}
				else
				{
					++zeroSize;
					spaces = false;
				}
			}
			if (zeroSize <= s2)
			{
				for (i = 0; i < resultSize - s2 - 1; ++i)
				{
					cout << " ";
				}
				for (i = 0; i < s2 + 1; ++i)
				{
					cout << "-";
				}
			}
			else
			{
				for (i = 0; i < resultSize - zeroSize; ++i)
				{
					cout << " ";
				}
				for (i = 0; i < zeroSize; ++i)
				{
					cout << "-";
				}
			}
			cout << endl;
			int counter = 0;
			spaces = true;
			for (i = 0; i < result.size(); ++i, ++counter)
			{
				for (j = 0; j < resultSize - counter; ++j)
				{
					if (result[i][j] == 0 && spaces == true && j != resultSize - 1 - counter)
					{
						cout << " ";
					}
					else
					{
						if (spaces == true && j == resultSize - 1 - counter)
						{
							cout << result[i][j];
							break;
						}
						else if (spaces == true && j != resultSize - 1 - counter)
						{
							cout << result[i][j];
							spaces = false;
						}
						else if (spaces == false && j != resultSize - 1 - counter)
						{
							cout << result[i][j];
						}
						else
						{
							cout << result[i][j];
							break;
						}
					}
				}
				cout << endl;
				spaces = true;
			}
			for (i = 0; i < resultSize; ++i)
			{
				cout << "-";
			}
			cout << endl;
			for (i = 0; i < resultSize; ++i)
			{
				cout << compResult[i];
			}
		}
	}
	cout << endl;
}





int main()
{
	unsigned int i, j;
	int T;
	cin >> T;
	cin.get();
	for (i = 0; i < T; ++i)
	{
		string line;
		getline (cin, line);
		vector <int> n1, n2;
		int oper = -1;
		for (j = 0; (line[j] != '+' && line[j] != '-' && line[j] != '*'); ++j)
		{
			n1.push_back (line[j] - 48);
		}
		switch (line[j])
		{
			case ('+'):
			{
				oper = 0;
				break;
			}
			case ('-'):
			{
				oper = 1;
				break;
			}
			case ('*'):
			{
				oper = 2;
				break;
			}
		}
		++j;
		for (; j < line.size(); ++j)
		{
			n2.push_back (line[j] - 48);
		}
		switch (oper)
		{
			case (0):
			{
				add (&n1, &n2);
				break;
			}
			case (1):
			{
				subtr (&n1, &n2);
				break;
			}
			case (2):
			{
				mult (&n1, &n2);
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
