#include <iostream>
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
  
    cout<<"Do you want to add Met's friend? <y/n> ";
    char play;
    cin>>play;
    play = tolower(play);
    for (;play=='y';)
    {
        cout<<"Enter Met's friend name: ";
        cin.get();
        getline(cin, temp);
        Met.insert(temp);
        cout<<"Want more friends? <y/n> ";
        cin>>play;
        play=tolower(play);
    }
    ostream_iterator<string, char> out1(cout," ");
    copy(Met.begin(), Met.end(), out1);
    cout<<endl;

    cout<<"Do you want to add Pet's friend? <y/n> ";
    cin>>play;
    play = tolower(play);
    for (;play=='y';)
    {
        cout<<"Enter Pet's friend name: ";
        cin.get();
        getline(cin, temp);
        Pet.insert(temp);
        cout<<"Want more friends? <y/n> ";
        cin>>play;
        play=tolower(play);
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
}
