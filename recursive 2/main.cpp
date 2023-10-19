#include <iostream>

using namespace std;
int fact(int x)
{
    if(x==0)
        return 1;
    else
        return x*fact(x-1);
}
int main()
{
    int z;
    cin>>z;
    cout<<fact(z);
return 0;
}
