#include <iostream>
using namespace std;

long double sum_values()
{
	return 0;
}
template<typename T>
long double sum_values(T value)
{
	return value;
}
template<typename T, typename... Args>
long double sum_values(T value, Args... args)
{
	long double temp=0;
	temp=value;
	return temp+=sum_values(args...);
}
int main()
{
	cout<<sum_values(3, 3.14, 5000, 3.12, 3444.12)<<endl;
}




