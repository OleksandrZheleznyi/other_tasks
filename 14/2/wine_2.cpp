#include "wine_2.h"

void Wine::Show() const
{
	cout<<"Wine: "<<Label()<<endl;
	int lim1=PairArray::first().size();
	cout<<"\t"<<"Year"<<"\t"<<"Bottles"<<endl;
	for(int i=0; i<lim1; i++)
	{
		cout<<"\t"<<PairArray::first().operator[](i)
			<<"\t"<<PairArray::second().operator[](i)<<endl;
	}
}
void Wine::GetBottles()
{
	int lim1=PairArray::first().size();
	cout<<"Enter "<<Label()<<" data for "<<lim1<<" year(s):"<<endl;
	for(int i=0; i<lim1; i++)
	{		
		cout<<"Enter year: ";
		cin>>PairArray::first().operator[](i);
		cout<<"Enter bottles for the year: ";
		cin>>PairArray::second().operator[](i);
	}	
}
int Wine::sum()
{
	return PairArray::second().sum();
}
