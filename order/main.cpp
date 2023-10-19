#include <iostream>

using namespace std;

int main()
{
int x=0,num[10];

cout<<"enter numbers to put in ascending order"<<endl;
while(x<10)
{
cin>>num[x];
x++;
}
cout<<"the numbers you entered are {";
for(int a=0;a<10;a++)
    cout<<num[a]<<" ";
    cout<<"}"<<endl;
int r1=-1,r2=-2;
for(int q=0;q<10;q++)
{
if(num[q]>r1)
r1=num[q];
}
for(int a=0;a<10;a++)
{
if(num[a]>r2&&r2<r1)
r2=num[a];
}
cout<<r1;
cout<<r2;


return 0;
}
