#include "cow.h"

void cal1(Cow &);
void cal2(Cow);

int main()
{
	Cow a;
	Cow b("Sas", "football", 23);
	Cow c("Sanya", "run", 21);
	//a=c;
	a.ShowCow();
	b.ShowCow();
	c.ShowCow();

	cal1(a);
	a.ShowCow();
	cal2(b);
	b.ShowCow();
	Cow d=c;
	d.ShowCow();
	Cow e;
	e=a;
	e.ShowCow();
}
void cal1(Cow & rs)
{
	rs.ShowCow();
}
void cal2(Cow r)
{
	r.ShowCow();
}