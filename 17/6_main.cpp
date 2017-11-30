#include "6.h"
#include <cstdlib> 
#include <cstring>

const char * file = "6.txt";

int main()
{
	char ch;
    ifstream fin;
    fin.open(file);
    
    if (fin.is_open())
    {
        cout<<"Here are the current contents of the "<<file<<" file:\n";
        for ( ;fin.get(ch); )
        {	
            cout<<ch;
        }    
        fin.close();
    }
    
	//add new names
    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr<<"Can't open "<<file<<" file for output.\n";
        exit(EXIT_FAILURE);
    }
    //
    const int MAX=3;

    abstr_emp * pc[MAX];           
    
    for (int i=0; i<MAX; i++)
    {
        char choice;
        cout<<"Enter the category:\n"
            <<"e: employee  m: manager  "
            <<"f: fink  h: highfink  q: quit\n";
        cin>>choice;
        for ( ;strchr("emfhq", choice) == NULL; )
        {
            cout << "Please enter a e, m, f, h or q: ";
            cin >> choice;
        }
        if (choice== 'q')
                break;
        switch (choice)
        {
            case 'e':   pc[i] = new employee;
                        break;
            case 'm':   pc[i] = new manager;
                        break;
            case 'f':   pc[i] = new fink;
                        break;
            case 'h':   pc[i] = new highfink;
                        break;
        }
        cin.get();
        pc[i]->SetAll();
        pc[i]->WriteAll(fout);
    }
    cout<<endl;

	//show revised file
    fin.clear();    //not necessary for some compilers
    fin.open(file);
    if (fin.is_open())
    {
        int i=0;
        int classtype;
        for ( ;(fin>>classtype).get(ch); )
        {
            switch (classtype)
            {
                case Employee : pc[i] = new employee;
                                break;
                case Manager  : pc[i] = new manager;
                                break;
                case Fink     : pc[i] = new fink;
                                break;
                case Highfink : pc[i] = new highfink;
                                break;
            }
            pc[i++]->GetAll(fin);
        }
    }
    cout<<"Recovery contents of the "<<file<<" file:"<<endl;
    for (int i=0; i<MAX; i++)
    {
        pc[i]->ShowAll();
        cout<<endl;
    }
}