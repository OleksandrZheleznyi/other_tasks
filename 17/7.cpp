#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void ShowStr(const string & s);
void GetStrs(ifstream & ifs, vector<string> & v);

class Store
{
private:
    ofstream & os;
public:
    Store(ofstream & f) : os(f) {}
    void operator()(const string & s)
    {
        int len=s.size();
        os.write((char *)&len, sizeof(size_t));
        os.write(s.data(), len);
    }
};
int main()
{
	vector<string> vostr;
    string temp;
    //Get line
    cout<<"Enter string (empty line to quit):\n";
    for ( ;getline(cin, temp) && temp[0]!='\0'; )
    {
        vostr.push_back(temp);
    }    
    cout<<"Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);
    //Save in file
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    //Restore the contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr<<"Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout<<"\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
}
void ShowStr(const string & s)
{
    cout<<s<<endl;
}
void GetStrs(ifstream & ifs, vector<string> & v)
{
    char ch;
    int len;
    for ( ;ifs.read((char *)&len, sizeof(size_t)); )
    {
    string temp;
        for (int i=0; i<len; i++)
        {
            ifs.read((char*)&ch, sizeof(ch));
            temp+=ch;
        }
        v.push_back(temp);
    }    
}
