// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class bad_hmean : public logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0, 
    const string & s="bad arguments to hmean(), invalid arguments: a = -b\n") 
        : v1(a), v2(b), logic_error(s) {}
    
};
class bad_gmean : public logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0,
    const string & s="gmean() arguments should be >= 0\n") 
    : v1(a), v2(b), logic_error(s) {}
};
