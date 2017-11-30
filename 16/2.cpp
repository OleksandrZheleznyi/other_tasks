#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool palindrom(string & s);

int main()
{
	cout<<"Enter string: ";
	string palin;
	getline(cin, palin);
	cout<<palin<<endl;

	for (int i=0; i<palin.size(); i++)
	{
		if (isupper(palin[i]))
		{	
			palin[i]=tolower(palin[i]);
		}	
		if (ispunct(palin[i]))
		{	
			string::iterator last1;
			last1=remove(palin.begin(), palin.end(), palin[i]);
			palin.erase(last1, palin.end()-1);//????
		}
	}
	string::iterator last;
	last=remove(palin.begin(), palin.end(), ' ');
	palin.erase(last, palin.end());

	cout<<palin<<endl;
	cout<<palindrom(palin)<<endl;
}
bool palindrom(string & s)
{
	int a1size=s.size();
	for(int i=0; i<a1size; i++)
	{	
		if(s[i]!=s[(a1size-1)-i])
		{	
			return false;
		}	
	}
	return true;	
}