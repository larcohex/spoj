#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	cin.get();
	for (int i=0; i<t; ++i)
	{
		int a, b;
		cin >> a >> b;
		cin.get();
		if (b==0)
			cout<<1<<endl;
		else if (a%10==0)
			cout<<0<<endl;
		else if (a%10==1)
			cout<<1<<endl;
		else if (a%10==5)
			cout<<5<<endl;
		else if (a%10==6)
			cout<<6<<endl;
		else if (a%10==2||a%10==3||a%10==7||a%10==8)
		{
			int l=b%4,r=a%10;
			if (l==0)
				l=4;
			for (int i=1;i<l;++i)
				r=(r*a)%10;
			cout<<r<<endl;				
		}
		else if (a%10==4 || a%10==9)
		{
			int l=b%2,r=a%10;
			if (l==0)
				l=2;
			for (int i=1;i<l;++i)
				r=(r*a)%10;
			cout<<r<<endl;				
		}
	}
}
