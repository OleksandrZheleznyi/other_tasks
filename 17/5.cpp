#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	string temp;
    set<string> Met;
    set<string> Pet;
    set<string> friends;

    ifstream fin;
    fin.open("mat.dat");

    if (fin.is_open())
    {
        for ( ;getline(fin, temp); )
        {
            cout<<temp<<endl;
            Met.insert(temp);
        }
    }
    else
    {
        cerr<<"Can't open"<<endl;
        exit(EXIT_FAILURE);
    }
    ostream_iterator<string, char> out1(cout," ");
    copy(Met.begin(), Met.end(), out1);
    cout<<endl;

    fin.close();
    fin.clear();

    fin.open("pat.dat");

    if (fin.is_open())
    {
        for ( ;getline(fin, temp); )
        {
            cout<<temp<<endl;
            Pet.insert(temp);
        }
    }
    else
    {
        cerr<<"Can't open"<<endl;
        exit(EXIT_FAILURE);
    }
    ostream_iterator<string, char> out2(cout," ");
    copy(Pet.begin(), Pet.end(), out2);
    cout<<endl;

    cout<<"Met and Pet friends:"<<endl;

    set_union(Met.begin(), Met.end(), Pet.begin(), Pet.end(), 
            insert_iterator<set<string> >(friends, friends.begin()));

    ostream_iterator<string, char> out(cout," ");
    copy(friends.begin(), friends.end(), out);
    cout<<endl;

    ofstream fout;
    fout.open("matnpat.dat");

    ostream_iterator<string, char> ft(fout,"\n");
    copy(friends.begin(), friends.end(), ft);
  
    fin.close();
}




