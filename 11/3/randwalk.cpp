// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    unsigned long max = 0;
    unsigned long min = 0;
    unsigned long average = 0;
    unsigned long temp = 0;

    int number;
    cout << "Enter number try: ";
    cin >> number;

    unsigned long mas[number];

    cout << "Enter target distance (q to quit): ";
    while (cin>>target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        for (int i=0; i<number; i++)
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            mas[i]=steps;     
            cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
            cout << result << endl;
            result.polar_mode();
            cout << " or\n" << result << endl;
            cout << "Average outward distance per step = "
                << result.magval()/steps << endl;
            steps = 0;
            result.reset(0.0, 0.0);
        }
        min=mas[0];
        for (int i=0; i<number; i++)
        {
            if(min>mas[i])
                min=mas[i];
            if(mas[i]>max)
                max=mas[i];
            temp += mas[i];
        }
        average=temp/number;
        cout<<"Max: "<<max<<endl;
        cout<<"Min: "<<min<<endl;
        cout<<"Average: "<<average<<endl;
        cout << "Enter target distance (q to quit): ";      
    }
    cout << "Bye!\n";
    //cin.get();
    //cin.get();
    //return 0; 
}
