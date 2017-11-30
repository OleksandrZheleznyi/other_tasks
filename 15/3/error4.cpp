#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch(basic & b)
        {
            cout<<b.what();
            b.Show();
            break;
        }
    }
    cout << "Bye!\n";
}
double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return sqrt(a * b); 
}
