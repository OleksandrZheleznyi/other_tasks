#include "6.h"

//abstr_emp methods
abstr_emp::~abstr_emp() {}

void abstr_emp::SetAll()
{
	cout<<"Enter firstname: ";
    getline(cin, fname);
    cout<<"Enter lastdname: ";
    getline(cin, lname);
    cout<<"Enter job: ";
    getline(cin, job);
}
void abstr_emp::ShowAll() const
{
	cout<<"Firstname is: "<<fname<<endl;
    cout<<"Lastname is: "<<lname<<endl;
    cout<<"Job is: "<<job<<endl;
}
//
void abstr_emp::WriteAll(ofstream & ofs)
{
	ofs<<fname<<endl;
	ofs<<lname<<endl;
	ofs<<job<<endl;
}
void abstr_emp::GetAll(ifstream & ifs)
{
    getline(ifs, fname);
    getline(ifs, lname);
    getline(ifs, job);
}
//
ostream & operator<<(ostream & os, const abstr_emp & e)
{
	os<<"Fname: "<<e.fname<<", "<<"Lname: "<<e.lname;
	return os;
}
//employee methods
void employee::SetAll()
{
	cout<<"Enter data for employee:"<<endl;
    abstr_emp::SetAll();
}
void employee::ShowAll() const
{
	cout<<"Show data employee:"<<endl;
	abstr_emp::ShowAll();
}
void employee::WriteAll(ofstream & ofs)
{
	ofs<<Employee<<endl;
	abstr_emp::WriteAll(ofs);
}
void employee::GetAll(ifstream & ifs)
{
    abstr_emp::GetAll(ifs);
}
//manager methods
void manager::SetAll()
{
	cout<<"Enter data for manager:"<<endl;
	abstr_emp::SetAll();
	cout<<"Enter inchargeof: ";
	cin>>inchargeof;
}
void manager::ShowAll() const
{
	cout<<"Show data for manager:"<<endl;
	abstr_emp::ShowAll();
	cout<<"Show inchargeof: "<<inchargeof<<endl;
}
//
void manager::WriteAll(ofstream & ofs)
{
	ofs<<Manager<<endl;
	abstr_emp::WriteAll(ofs);
	ofs<<inchargeof<<endl;
}
void manager::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	ifs>>inchargeof;
}
//
//fink methods
void fink::SetAll()
{
	cout<<"Enter data for fink:"<<endl;
	abstr_emp::SetAll();
	cout<<"Enter reportsto: ";
	getline(cin, reportsto);
}	
void fink::ShowAll() const
{
	cout<<"Show data for fink:"<<endl;
	abstr_emp::ShowAll();
	cout<<"Show reportsto: "<<reportsto<<endl;
}
//
void fink::WriteAll(ofstream & ofs)
{
	ofs<<Fink<<endl;
	abstr_emp::WriteAll(ofs);
	ofs<<reportsto<<endl;
}
void fink::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	getline(ifs, reportsto);
}
//
//highfink methods
void highfink::SetAll()
{
	cout<<"Enter data for highfink:"<<endl;
	abstr_emp::SetAll();
	cout<<"Enter inchargeof: ";
	cin>>manager::InChargeOf();
	cout<<"Enter reportsto: ";
	cin.get();
	getline(cin, fink::ReportsTo());
}
void highfink::ShowAll() const
{
	cout<<"Show data for highfink:"<<endl;
	abstr_emp::ShowAll();
	cout<<"Show inchargeof: "<<manager::InChargeOf()<<endl;
	cout<<"Show reportsto: "<<fink::ReportsTo()<<endl;
}
void highfink::WriteAll(ofstream & ofs)
{
	ofs<<Highfink<<endl;
	abstr_emp::WriteAll(ofs);
	ofs<<manager::InChargeOf()<<endl;
	ofs<<fink::ReportsTo()<<endl;
}
void highfink::GetAll(ifstream & ifs)
{
	abstr_emp::GetAll(ifs);
	ifs>>manager::InChargeOf();
	ifs.get();
	getline(ifs, fink::ReportsTo());
}