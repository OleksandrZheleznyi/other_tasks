#ifndef DMA_H_
#define DMA_H_
#include <iostream>
using namespace std;

// ABC class
class ABC
{
private:
    char * label;
    int rating;
protected:
    const char * Label() const { return label; }
    int Rating() const { return rating; }    
public:
    ABC(const char * l = "null", int r = 0);
    ABC(const ABC & a);
    virtual ~ABC();
    ABC & operator=(const ABC & a);
    
    virtual void View() const = 0; 
};

class baseDMA : public ABC
{
public:
    baseDMA(const char * l = "null", int r = 0) : ABC(l, r) {}
    baseDMA(const baseDMA & rs) : ABC(rs) {}
    ~baseDMA() {}
    virtual void View() const;
};
class lacksDMA : public ABC
{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    ~lacksDMA() {}
    virtual void View() const;
};

class hasDMA : public ABC
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    virtual void View() const;
};
#endif