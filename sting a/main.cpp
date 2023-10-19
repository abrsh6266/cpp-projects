#include <iostream>

using namespace std;
class point
{
private:
    int x=20,y=40;
public:
point()
{
    cout<<"the numbers are :"<<x<<" and "<<y<<endl;
}
~point()
{
    cout<<"destroyed entity"<<endl;
     cout<<"the numbers are :"<<x<<" and "<<y<<endl;
}
};

int main()
{
    point z;
    return 0;
}
