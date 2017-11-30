#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

using namespace std;

class Complex
{
private: 
	double x;//real
	double y;//imaginary
public:
	Complex();
	Complex(double a, double b);
	~Complex();
	// operator overloading
	Complex operator+(const Complex & n) const;
	Complex operator-(const Complex & n) const;
	Complex operator~() const;
	Complex operator*(const Complex & n) const;
	Complex operator*(double m) const;
	 // friends
	friend Complex operator*(double m, const Complex & n);

	friend ostream & operator<<(ostream & os, const Complex & v);
	friend istream & operator>>(istream & is, Complex & v);
       
};
#endif