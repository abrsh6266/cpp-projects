#include <iostream>
#define maxi 100
using namespace std;
float ll()
{
int ab[maxi];
int x;
cout<<"Enter the number of elements to store..."<<endl;
cin>>x;
for(int a=0;a<x;a++)
{
cout<<"enter number "<<a+1<<":";
cin>>ab[a];
}
cout<<"the numbers you entered are {";
for(int a=0;a<x;a++)
{
cout<<" "<<ab[a]<<" ";
}cout<<"}"<<endl;
int v=ab[x-1],n;
for(int a=x-2;a>=0;a--)
{
if(ab[a]>=v)
{v=ab[a];
n=a+1;
}
}
cout<<"the largest number is "<<v<<" which occurs at cell "<<n;
return 0;
}
int main()
{
    ll();
    return 0;
}
