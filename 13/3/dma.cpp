#include "dma.h"
#include <cstring>
#include <iostream>
using namespace std;

//ABC methods
ABC::ABC(const char * l, int r)
{
    label=new char[strlen(l)+1];
    strcpy(label, l);
    rating=r;
}
ABC::ABC(const ABC & a)
{
    label=new char[strlen(a.label)+1];
    strcpy(label, a.label);
    rating=a.rating;
}
ABC & ABC::operator=(const ABC & a)
{
    if(this==&a)
        return * this;
    delete [] label;
    label=new char[strlen(a.label)+1];
    strcpy(label, a.label);
    rating=a.rating;
    return * this;
}
ABC::~ABC()
{
    delete [] label;
}
// baseDMA methods
void baseDMA::View() const
{
    cout<<"Label: "<<Label()<<endl;
    cout<<"Rating: "<<Rating()<<endl;
}
// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r) : ABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}
lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : ABC(rs)
{
    strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}
void lacksDMA::View() const
{
    cout<<"Color: "<<color<<endl;
    cout<<"Label: "<<Label()<<endl;
    cout<<"Rating: "<<Rating()<<endl;
}
// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) : ABC(l, r)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const baseDMA & rs) : ABC(rs)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs) : ABC(hs) 
{
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return * this;
    ABC::operator=(hs);  // copy base portion
    delete [] style;         // prepare for new style
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return * this;
}
void hasDMA::View() const
{
    cout<<"Style: "<<style<<endl;
    cout<<"Label: "<<Label()<<endl;
    cout<<"Rating: "<<Rating()<<endl;
}
