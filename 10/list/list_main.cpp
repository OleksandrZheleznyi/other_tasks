#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int number;
	List spisok;

	if (spisok.isempty())
		cout<<"List is empty"<<endl;
	
	cout<<"Enter 'a' to add, 'q' to quit: ";
	for ( ;cin>>ch && ch!='q'; )
	{
		//for(;cin.get()!='\n';);
		if(ch=='a')
		{
			if (spisok.isfull())
				cout<<"List alredy full"<<endl;
			else
			{	
				cout<<"Enter number: ";
				cin>>number;
				spisok.add(number);
			}	
		} 
		cout<<"Next enter 'a' to add, 'q' to quit: "; 	
	}

	spisok.visit(pam);
	spisok.visit(show);

	cout<<"Bye"<<endl;
}