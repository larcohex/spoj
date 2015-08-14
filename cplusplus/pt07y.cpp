#include <iostream>
#include <list>

using namespace std;


class HashTable
{
	private:
		int s;
		list <int> *table;
	public:
		HashTable()
		{
			this->s = 1999;
			this->table = new list <int> [1999];
		}
		~HashTable()
		{
			this->s = 0;
			delete [] this->table;
		}
		unsigned int hash (int value)
		{
			const unsigned int prime = 709607;
			unsigned int hash = 2166136261;
			const char *str = (char *)(&value);
			unsigned int len = sizeof (int);
			while (len >= 2 * sizeof (unsigned int))
			{
				hash = prime * (hash ^ (((*(unsigned int *)(str) << 5) | (*(unsigned int *)(str) >> 27)) ^ (*(unsigned int *)(str + 4))));
				len = len - 2 * sizeof (unsigned int);
				str = str + 2 * sizeof (unsigned int);
			}
			if (len & sizeof (unsigned int))
			{
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
			}
			if (len & sizeof (unsigned short))
			{
				hash = prime * (hash ^ (*(unsigned short *)(str)));
				str = str + sizeof (unsigned short);
			}
			if (len & 1)
			{ 
				hash = prime * (hash ^ *str);
			}
			return hash ^ (hash >> 16);
		}
		unsigned int search (int value)
		{
			unsigned int key = (this->hash (value)) % (this->s);
			for (list <int> :: iterator itr = ((this->table)[key]).begin(); itr != ((this->table)[key]).end(); ++itr)
			{
				if (*itr == value)
				{
					return key;
				}
			}
			throw 0;
		}
		void insert (int value)
		{
			try
			{
				this->search (value);
			}
			catch (int e)
			{
				unsigned int key = (this->hash(value)) % (this->s);
				((this->table)[key]).push_back (value);
			}
		}
};	


int main()
{
	int V, E;
	HashTable nodes;
	bool isGraph = false;
	cin >> V >> E;
	if (V - 1 != E)
		isGraph = true;
	cin.get();
	int node1, node2;
	cin >> node1 >> node2;
	nodes.insert (node1);
	nodes.insert (node2);
	for (int i = 1; i < E; ++i)
	{
		cin.get();
		cin >> node1 >> node2;
		if (!isGraph)
		{
			bool temp = false;
			try
			{
				nodes.search (node1);
				temp = true;
				nodes.search (node2);
				isGraph = true;
			}
			catch (int e)
			{
				if (temp)
					nodes.insert (node2);
				else
				{
					try
					{
						nodes.search (node2);
						nodes.insert (node1);
					}
					catch (int e)
					{
						isGraph = true;
					}
				}
			}
		}
	}
	if (isGraph)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
