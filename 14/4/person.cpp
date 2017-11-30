#include "person.h"
#include <cstdlib>
#include <ctime>

//Person methods
Person::~Person() { }
//Protected methods
void Person::Data() const
{
    cout<<"Firstname is: "<<firstname<<endl;
    cout<<"Secondname is: "<<secondname<<endl;
}
void Person::Get()
{
    cout<<"Enter firstname: "<<endl;
    getline(cin, firstname);
    cout<<"Enter secondname: "<<endl;
    getline(cin, secondname);
}
//Gunslinger methods
void Gunslinger::Set()
{
    cout<<"Enter name for Gunslinger"<<endl;
    Person::Get();
    Get();
}
void Gunslinger::Show() const
{
    cout<<"Gunslinger info"<<endl;
    Person::Data();
    Data();
    cout<<"Combat readiness: "<<Draw()<<endl;
}
double Gunslinger::Draw() const
{
    srand(time(NULL));
    return rand()%10+1;
}
//Protected methods
void Gunslinger::Data() const
{
    cout<<"Nick are: "<<nick<<endl;
}
void Gunslinger::Get()
{
    cout<<"Enter number nicks:"<<endl;
    cin>>nick;
}
//PokerPlayer methods
void PokerPlayer::Set()
{
    cout<<"Enter name for PokerPlayer"<<endl;
    Person::Get();
}
void PokerPlayer::Show() const
{
    cout<<"PokerPlayer info"<<endl;
    Data();
    cout<<"Random number with 1 to 52: "<<Draw()<<endl;
}
int PokerPlayer::Draw() const
{
    srand(time(NULL));
    return rand()%52+1;
}
//Protected methods
void PokerPlayer::Data() const
{
    Person::Data();
}
void PokerPlayer::Get()
{
    Person::Get();
}
//BadDude methods
//Protected methods
void BadDude::Data() const
{
    Person::Data();
    Gunslinger::Data();
}
void BadDude::Get()
{
    Person::Get();
    Gunslinger::Get();
}
void BadDude::Set()
{
    cout<<"Enter info for BadDude:"<<endl;
    Get();
}
double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}
int BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}
void BadDude::Show() const
{
    cout<<"BadDude info"<<endl;
    Data();
    cout<<"Combat readiness: "<<Gdraw()<<endl;
    cout<<"Random number with 1 to 52: "<<Cdraw()<<endl;
}
