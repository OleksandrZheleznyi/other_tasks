#include "dma.h"
#include <iostream>
using namespace std;

const int SIZE = 3;

int main()
{
    ABC * mas[SIZE]; 

    int temp_r;
    char temp_l[20];
    char temp_c[40];
    char num;

    for (int i = 0; i < SIZE; i++)
    {
        cout<<"Enter 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA: ";
        while (cin >> num && (num!='1' && num!='2' && num!='3'))
                cout <<"Enter either 1 or 2 or 3: ";
        while (cin.get() != '\n');     
        if (num=='1')
        {  
            cout<<"Enter label: ";
            cin.get(temp_l, 20);
            cin.get();
            cout<<"Enter rating: ";
            cin>>temp_r;
            mas[i]=new baseDMA(temp_l, temp_r);
        }   
        else if (num=='2')
        {  
            cout<<"Enter color: ";
            cin.get(temp_c, 40);
            cin.get();
            cout<<"Enter label: ";
            cin.get(temp_l, 20);
            cin.get();
            cout<<"Enter rating: ";
            cin>>temp_r;
            mas[i]=new lacksDMA(temp_c, temp_l, temp_r);
        }    
        else if (num=='3')
        {  
            cout<<"Enter style: ";
            cin.get(temp_c, 40);
            cin.get();
            cout<<"Enter label: ";
            cin.get(temp_l, 20);
            cin.get();
            cout<<"Enter rating: ";
            cin>>temp_r;
            mas[i]=new hasDMA(temp_c, temp_l, temp_r);
        }       
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        mas[i]->View();
        cout << endl;
    }           
    for (int i = 0; i < SIZE; i++)
    {
        delete mas[i]; 
    }
    cout << "Done.\n";      
}
