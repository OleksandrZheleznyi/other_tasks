#include "cd_2.h"
#include <iostream>
#include <cstring>
using namespace std;

Cd::Cd(const char * p, const char * l, int n, double x) 
{
	
	performers=new char[strlen(p)+1];
	strcpy(performers, p);
	label=new char[strlen(l)+1];
	strcpy(label, l);
	selections=n;
	playtime=x;
}
Cd::Cd(const Cd & d)
{
	performers=new char[strlen(d.performers)+1];
	strcpy(performers, d.performers);
	label=new char[strlen(d.label)+1];
	strcpy(label, d.label);
	selections=d.selections;
	playtime=d.playtime;	
}
Cd & Cd::operator=(const Cd & d)
{
	if(this==&d)
		return * this;
	delete [] performers;
	delete [] label;
	performers=new char[strlen(d.performers)+1];
	strcpy(performers, d.performers);
	label=new char[strlen(d.label)+1];
	strcpy(label, d.label);
	selections=d.selections;
	playtime=d.playtime;
	return * this;
}
Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}
void Cd::Report() const
{
	cout<<"Performers is: "<<performers<<endl;
	cout<<"Label is: "<<label<<endl;
	cout<<"Selections are: "<<selections<<endl;
	cout<<"Playtime are: "<<playtime<<endl;
}
//Classic
Classic::Classic(const char * pr, const char * s1, const char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	product=new char[strlen(pr)+1];
	strcpy(product, pr);
}
Classic::Classic(const char * pr, const Cd & d) : Cd(d)
{
	product=new char[strlen(pr)+1];
	strcpy(product, pr);
}
Classic::Classic(const Classic & c) : Cd(c)
{
	product=new char[strlen(c.product)+1];
	strcpy(product, c.product);	
}
Classic & Classic::operator=(const Classic & c)
{
	if(this==&c)
		return * this;
	Cd::operator=(c);
	delete [] product;
	product=new char[strlen(c.product)+1];
	strcpy(product, c.product);
	return * this;
}
Classic::~Classic()
{
	delete [] product;
}
void Classic::Report() const
{
	cout<<"Product is: "<<product<<endl;
	Cd::Report();
}
