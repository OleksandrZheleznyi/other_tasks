#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const long size=1000000;

int main()
{
    srand(time(0));

    vector<int> vi0(size);
    for (int i=0; i<size; i++)
    {
        vi0[i]=rand();
    }

    vector<int> vi(size);
    vi=vi0;

    list<int> li;
    li.insert(li.begin(), vi0.begin(), vi0.end());

    cout<<"Time sorting vector"<<endl;
    clock_t startvi=clock();
    sort(vi.begin(), vi.end());
    clock_t endvi=clock();
    cout<<(double)(endvi-startvi)/CLOCKS_PER_SEC<<endl;

    cout<<"Time sorting list"<<endl;
    clock_t startli=clock();
    li.sort();
    clock_t endli=clock();
    cout<<(double)(endli-startli)/CLOCKS_PER_SEC<<endl;
    
    //double free or corruption
    list<int> li2;
    li=li2;
    li.insert(li.begin(), vi0.begin(), vi0.end());
    
    cout<<"Time sorting list with copy in vector"<<endl;
    clock_t start=clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    clock_t end=clock();
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}
