#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////
class Worker   // an abstract base class
{
private:
    string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const string & s, long n) : fullname(s), id(n) {}
    virtual ~Worker() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const = 0;
};
class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};
class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    const static char * pv[Vtypes];    // string equivs of voice types
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};
// multiple inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter()  {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
            : Worker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
            : Worker(wk), Waiter(wk,p), Singer(wk,v) {}
    SingingWaiter(const Waiter & wt, int v = other)
            : Worker(wt),Waiter(wt), Singer(wt,v) {}
    SingingWaiter(const Singer & wt, int p = 0)
            : Worker(wt),Waiter(wt,p), Singer(wt) {}
    void Set();
    void Show() const; 
};
//////////////////////////////////////////////////////////////////////////////
template<typename Type>
class QueueTp
{
private:
    struct Node { Type item; struct Node * next;};
    enum {Q_SIZE = 10};
// private class members
    Node * front;       // pointer to front of QueueTp
    Node * rear;        // pointer to rear of QueueTp
    int items;          // current number of items in QueueTp
    const int qsize;    // maximum number of items in QueueTp
    // preemptive definitions to prevent public copying
    QueueTp(const QueueTp & q) : qsize(0) { }
    QueueTp & operator=(const QueueTp & q) { return * this; } 
public:
    QueueTp(int qs = Q_SIZE); // create queue with a qs limit
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Type & item); // add item to end
    bool dequeue(Type & item);       // remove item from front
};
// Queue methods
template<typename Type>
QueueTp<Type>::QueueTp(int qs) : qsize(qs)
{
    front = rear = NULL;    // or nullptr
    items = 0;
}
template<typename Type>
QueueTp<Type>::~QueueTp()
{
    Node * temp;
    while (front != NULL)   // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}
template<typename Type>
bool QueueTp<Type>::isempty() const
{
    return items == 0;
}
template<typename Type>
bool QueueTp<Type>::isfull() const
{
    return items == qsize;
}
template<typename Type>
int QueueTp<Type>::queuecount() const
{
    return items;
}
// Add item to queue
template<typename Type>
bool QueueTp<Type>::enqueue(const Type & item)
{
    if (isfull())
        return false;
    Node * add = new Node;  // create node
// on failure, new throws std::bad_alloc exception
    add->item = item;       // set node pointers
    add->next = NULL;       // or nullptr;
    items++;
    if (front == NULL)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}
// Place front item into item variable and remove from queue
template<typename Type>
bool QueueTp<Type>::dequeue(Type & item)
{
    if (front == NULL)
        return false;
    item = front->item;     // set item to first item in queue
    items--;
    Node * temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}
#endif
