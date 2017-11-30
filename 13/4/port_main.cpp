#include "port.h"

int main()
{
	Port a("Gallo", "tawny", 20);
	a.Show();
	cout<<a<<endl;
	int temp;
	temp=a.BottleCount();
	cout<<temp<<endl;
	a+=5;
	cout<<a<<endl;		
	a-=10;
	cout<<a<<endl;
	temp=a.BottleCount();
	cout<<temp<<endl;
	VintagePort b("Gallo", "tawny", 20, "Sasha Zhel", 1992);
	a=b;
	a.Show();
	b.Show();
	cout<<b<<endl;
	cout<<b.BottleCount()<<endl;
	b+=100;
	b.Show();
	b-=200;
	b.Show();   
}
