#include <iostream>
using namespace std;

int main()
{
    int x,y,r=100;
    cin>>x>>y;
    if(x<y)
    {
        r=y;
        y=x;
        x=r;
    }
    while(r!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    cout <<x<< endl;
    return 0;
}
