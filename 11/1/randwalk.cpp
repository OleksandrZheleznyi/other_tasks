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
    //Вставка
    ofstream outFile;
    outFile.open("vector.txt"); 
    //
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
       
        outFile<<"Target Distance: "<<target<<", "<<"Step Size: "<<dstep<<endl;
      
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            outFile<<steps<<": ";
            outFile<<result<<endl;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        //outFile<<"Target Distance: "<<target<<", "<<"Step Size: "<<dstep<<endl;
        outFile<<"After "<<steps<< " steps, the subject "
            "has the following location:\n";
        outFile<<result<<endl;    
        result.polar_mode();
        cout << " or\n" << result << endl;
        outFile << " or\n" << result << endl;
        //outFile<<result<<endl;
        outFile << "Average outward distance per step = "
            << result.magval()/steps << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    
    outFile.close();s

    //cin.get();
    //cin.get();
    //return 0; 
}
