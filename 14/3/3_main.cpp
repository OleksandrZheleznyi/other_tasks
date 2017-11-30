#include "3.h"
#include <cstring>

const int SIZE = 3;

int main()
{
    QueueTp<Worker *> lolas(SIZE);

    Worker * temp;

   	int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout<< "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
                break;
        switch(choice)
        {
            case 'w':   temp = new Waiter;
                        break;
            case 's':   temp = new Singer;
                        break;
            case 't':   temp = new SingingWaiter;
                        break;
        }
        cin.get();
        temp->Set();
        lolas.enqueue(temp);  
    }
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas.dequeue(temp);
        temp->Show();
        delete temp;
    }
    cout << "Bye.\n";
}
