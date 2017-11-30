#include "complex0.h"

//#include <iostream>

//using namespace std;

Complex::Complex()
{
	x=0.0;
	y=0.0;
}
Complex::Complex(double a, double b)
{
	x=a;
	y=b;
}
Complex::~Complex()
{

}
Complex Complex::operator+(const Complex & n) const
{
	return Complex(x+n.x, y+n.y);
}
Complex Complex::operator-(const Complex & n) const
{
	return Complex(x-n.x, y-n.y);
}
Complex Complex::operator~() const
{
	return Complex(x, -y);
}
Complex Complex::operator*(const Complex & n) const
{
	return Complex(x*n.x - y*n.y, x*n.y + y*n.x);
}
Complex Complex::operator*(double m) const
{
	return Complex(m * x, m * y);
}
Complex operator*(double m, const Complex & n)
{
	return n * m;
}
ostream & operator<<(std::ostream & os, const Complex & v)
{
    os<<"("<<v.x<<","<<v.y<<"i)";
  	return os; 
}
istream & operator>>(istream & is, Complex & v)
{
	cout<<"real: ";
	if(is>>v.x)
	{		
	cout<<"imaginary: ";
	is>>v.y;
	}
	return is;
}
