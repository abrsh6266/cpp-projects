#include <iostream>
#include<cmath>
using namespace std;
int q;
int gcf(int &x,int &y)
{
while(1)
{
if(x<y)
{
for(int a=x;a>0;a--)
{
if(x%a==0&&y%a==0)
    {q=a;
    break;}
}
}
else if(x>y)
{
for(int a=y;a>0;a--)
{
if(x%a==0&&y%a==0)
    {q=a;
    break;}
}
}
break;}
cout<<"their gcd is "<<q;
return 0;}

int main()
{
int v,y;
cin>>v>>y;
gcf(v,y);
return 0;
}
