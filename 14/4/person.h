#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
    string firstname;
    string secondname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person() : firstname("None"), secondname("None") {}
    Person(const string & fn, const string & sn)
             : firstname(fn), secondname(sn) {}
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0; 
};
class Gunslinger : virtual public Person
{
private:
    int nick;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger() : Person(), nick(0) {}
    Gunslinger(const string & fn, const string & sn, int n=0) : Person(fn, sn), nick(n) {}
    Gunslinger(const Person & fs, int n=0) : Person(fs), nick(n) {}
    void Set();
    double Draw() const;
    void Show() const;       
};
class PokerPlayer : virtual public Person
{
protected:
    void Data() const;
    void Get();
public:
    PokerPlayer() : Person() {}
    PokerPlayer(const string & fn, const string & sn) : Person(fn, sn) {}
    PokerPlayer(const Person & fs) : Person(fs) {}//?
    void Set();
    int Draw() const;
    void Show() const;
};
class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get();
public:
    BadDude() {}
    BadDude(const string & fn, const string & sn, int n=0)
                : Person(fn, sn), Gunslinger(fn, sn, n), PokerPlayer(fn, sn) {}
    BadDude(const Person & fs, int n=0)
                : Person(fs), Gunslinger(fs, n), PokerPlayer(fs) {}
    BadDude(const Gunslinger & gl)   
                : Person(gl), Gunslinger(gl), PokerPlayer(gl) {}
    BadDude(const PokerPlayer & pp, int n=0)
                : Person(pp), Gunslinger(pp, n), PokerPlayer(pp) {}  
    void Set();                                        
    double Gdraw() const;
    int Cdraw() const;
    void Show() const;
};
#endif
