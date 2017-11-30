#ifndef WINE_H_2_
#define WINE_H_2_
#include <iostream>
#include <string>
#include <valarray>
using namespace std;

template <typename T1, typename T2>
class Pair
{
private:	
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
	Pair() {}
};
template <typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
	return a;
}
template <typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
	return b;
}

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
class Wine :  private string, private PairArray
{
public:
	Wine() : string("None"), PairArray(ArrayInt(), ArrayInt()) {}
	Wine(const char * l, int y) : string(l), PairArray(ArrayInt(y), ArrayInt(y)) {}
	Wine(const char * l, int y, const int yr[], const int bot[])
			: string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	~Wine() {}
	void Show() const;
	void GetBottles();
	const string & Label() const { return (const string &) *this; }
	int sum();
};
#endif