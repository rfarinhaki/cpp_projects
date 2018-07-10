#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct {
    int num;
    char str[256];
} struc;


int main()
{
    char *ptr;
    string st;
    ptr=(char*)malloc(40*sizeof(char));
    cout<<"struc"<<sizeof(struc)<<endl;
    getline(cin,st);
    cout<<"String:"<<st<<endl;
}
