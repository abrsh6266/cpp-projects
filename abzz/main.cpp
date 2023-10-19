#include <iostream>
#include <string>
using namespace std;

struct name
{
    string nam;
    int ID;
};
name *t;
name s;
int main()
{
t=&s;
s.ID=100;
cout<<t->ID<<endl;
(*t).ID=60;
cout<<s.ID;
    return 0;
}
