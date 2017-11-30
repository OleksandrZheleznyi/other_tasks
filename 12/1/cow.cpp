#include "cow.h"
#include <cstring>
#include <iostream>
using namespace std;

int Cow::num=0;

Cow::Cow()
{
	len=5;
	strcpy(name, "Sasha");
	hobby=new char[1];
	hobby[0]='\0';
	weight=0;
	num++;
	cout<<num<<" default"<<endl;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy(name, nm);
	len=strlen(ho);
	hobby=new char[len+1];
	strcpy(hobby, ho);
	weight=wt;
	num++;
	cout<<num<<" no default"<<endl;
}
Cow::Cow(const Cow & c)
{
	num++;
	len=c.len;
	hobby=new char[len+1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight=c.weight;
	cout<<num<<" const copy"<<endl;
}
Cow::~Cow()
{
	--num;
	cout<<num<<" left"<<endl;
	delete [] hobby;
}
Cow & Cow::operator=(const Cow & c)
{
	if (this==&c)
		return *this;
	delete [] hobby;
	len=c.len;
	hobby=new char[len+1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight=c.weight;
	return *this;
}
void Cow::ShowCow() const
{
	cout<<"Name is: "<<name<<endl;
	cout<<"Hobby is: "<<hobby<<endl;
	cout<<"Weight is: "<<weight<<endl;
}