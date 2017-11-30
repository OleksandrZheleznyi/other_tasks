#include "emp.h"

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
ostream & operator<<(ostream & os, const abstr_emp & e)
{
	//os<<"Fname: "<<e.fname<<", "<<"Lname: "<<e.lname<<", "<<"Job: "<<e.job;
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