#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
	unsigned int i, j;
	int n;
	cin >> n;
	cin.get();
	for (i = 0; i < n; ++i)
	{
		string a;
		getline (cin, a);
		vector <char> stack, queue;
		for (j = 0; j < a.size(); ++j)
		{
			if (a[j] == '(' || a[j] == '^')
			{
				stack.push_back (a[j]);
			}
			else if ( (a[j] == '+') || (a[j] == '-') || (a[j] == '*') || (a[j] == '/') )
			{
				if (stack.empty())
				{
					stack.push_back (a[j]);
				}
				else
				{
					char temp = stack.back();
					if ( (a[j] == temp) || ((a[j] == '+') && (temp == '-')) || ((a[j] == '-') && (temp == '+')) || ((a[j] == '*') && (temp == '/')) || ((a[j] == '/') && (temp == '*')) )
					{
						while ( (stack.back() != '*') && (stack.back() != '/') && (stack.back() != '^') && (stack.back() != '(' ) && (!stack.empty()) )
						{
							queue.push_back (stack.back());
							stack.pop_back();
						}
						stack.push_back (a[j]);
					}
					else if ( (temp == '(') || ((a[j] == '*') && (temp == '-')) || ((a[j] == '*') && (temp == '+')) || ((a[j] == '/') && (temp == '-')) || ((a[j] == '/') && (temp == '+')) )
					{
						stack.push_back (a[j]);
					}
				}
			}
			else if (a[j] == ')')
			{
				while (stack.back() != '(')
				{
					queue.push_back (stack.back());
					stack.pop_back();
				}
				stack.pop_back();
			}
			else
			{
				queue.push_back (a[j]);
			}
		}
		while (!stack.empty())
		{
			queue.push_back (stack.back());
			stack.pop_back();
		}
		for (j = 0; j < queue.size(); ++j)
		{
			cout << queue[j];
		}
		cout << endl;
	}
	return 0;
}
