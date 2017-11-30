#include <iostream>
#include <stdexcept>
using namespace std;

class basic : public logic_error
{
private:
    double v1;
    double v2;
public:
    basic(double a = 0, double b = 0, const string & s="Error!")
        : v1(a), v2(b), logic_error(s) {}
    void Show() const {cout<<v1<<" "<<v2<<endl;}
};
class bad_hmean : public basic
{
public:
    bad_hmean(double a = 0, double b = 0, 
    const string & s="bad arguments to hmean(), invalid arguments: a = -b\n") 
        : basic(a, b, s) {}
};
class bad_gmean : public basic
{
public:
    bad_gmean(double a = 0, double b = 0, 
    const string & s="gmean() arguments should be >= 0\n") 
        : basic(a, b, s) {}

};

