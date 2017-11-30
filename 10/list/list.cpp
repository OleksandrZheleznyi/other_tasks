#include "list.h"
#include <iostream>

using namespace std;
List::List()
{
	//for (int i=0; i<MAX; i++)
	//	items[i]=0;
	top=0;
}
List::~List()
{
}
bool List::isempty() const
{
	return top == 0;
}
bool List::isfull() const
{
	return top == MAX;
}
bool List::add(int item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}
void pam(Item & a)
{
	a+=3;
}
void show(Item & a) 
{
	cout<<"Item "<<a<<endl;
}
void List::visit(void (*pf)(Item & a))
{
	for (int i=0; i<top; i++)
	{	
		(*pf)(items[i]);
	}	
}