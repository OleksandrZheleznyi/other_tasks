#ifndef CD_H_2_
#define CD_H_2_

class Cd
{
private:
	//char performers[50];
	//char label[20];
	char * performers;
	char * label;
	////
	int selections;
	double playtime;
public:
	Cd(const char * p="none", const char * l="none", int n=0, double x=0);
	virtual ~Cd();

	Cd(const Cd & d);//конструктор копирования

	virtual void Report() const;//show
	Cd & operator=(const Cd & d);//операция присваивания
};
class Classic : public Cd
{
private:
	char * product;
public:
	Classic(const char * pr="none", const char * p="none", const char * l="none", int n=0, double x=0);
	Classic (const char * pr, const Cd & d);
	~Classic();

	Classic(const Classic & c);

	Classic & operator=(const Classic & c);
	
	virtual void Report() const;
};
#endif