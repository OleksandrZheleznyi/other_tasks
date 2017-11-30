#ifndef LIST_H_
#define LIST_H_

typedef int Item;

void pam(Item &);
void show(Item &);
//void (*pf)(Item & a);
//pf=pam;

class List
{
private:
	enum {MAX=5};
	//static const int MAX=5;
	Item items[MAX];
	int top;
public:
	List();
	~List();
	bool isempty() const;
	bool isfull() const;
	bool add(int item);
	void visit(void (*pf)(Item &));
};
#endif