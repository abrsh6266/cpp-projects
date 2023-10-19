#include <iostream>
#include<vector>
using namespace std;
void ab(int z[],int x)
{
    for(int a=0;a<x;a++)
    {
        cin>>z[a];
    }
}
int main()
{
    int x;
    cin>>x;
    int q[x];
    ab(q,x);
    for(int a=0;a<x;a++)
    {
        cout<<q[a]<<", ";
    }

    return 0;
}
