#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack st;
	int sum=0;
	char ch;
	Item mas;
	cout<<"Enter 'a' to add, 'd' to delete, 'q' to quit: ";
	for ( ;cin>>ch && ch!='q'; )
	{
		for ( ;cin.get()!='\n'; );
		if (ch == 'a')
		{
			if (st.isfull())
				cout<<"stack alredy full"<<endl;
			else
			{	
				cout<<"Enter you fullname: ";
				cin.getline(mas.fullname, 35);
				cout<<"Enter you payment: ";
				cin>>mas.payment;
				st.push(mas);
			}	
		} 
		else if (ch == 'd')
		{
			if (st.isempty())
				cout<<"stack already empty"<<endl;
			else
			{	
				st.pop(mas);
				sum+=mas.payment;
				cout<<"Sum is: "<<sum<<endl;
			}	
		}
		cout<<"Next enter 'a' to add, 'd' to delete, 'q' to quit: "; 	
	}
	cout<<"Bye"<<endl;
}