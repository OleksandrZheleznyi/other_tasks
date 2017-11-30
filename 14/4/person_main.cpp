#include "person.h"
#include <cstring>

const int SIZE = 5;

int main()
{
    Person * lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "g: gunslinger  p: pokerplayer  "
            << "b: baddude  q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter  g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'g':   lolas[ct] = new Gunslinger;
                        break;
            case 'p':   lolas[ct] = new PokerPlayer;
                        break;
            case 'b':   lolas[ct] = new BadDude;
                        break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n"; 
}
