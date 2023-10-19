#include <iostream>

using namespace std;

int main()
{

int x;
q:
while(1)
{
cout<<"enter a positive number to know the divisor of it.or zero to quit."<<endl;
cin>>x;
if(x<0)
{
cout<<x<<" is negative number.try another"<<endl;
continue;
}
else if(x==0)
{cout<<"good bye :)";
break;}
else
{int y=x,z;
cout<<"the divisors of "<<x<<" are:"<<endl;
while(y>=1)
{
if(x%y==0)
{z=y;
y--;
cout<<z<<endl;
}
else
y--;
}}
cout<<"would you like to continue or not(y/n)"<<endl;
char l;
cin>>l;
switch(l)
{
case 'y':
goto q;
break;
case 'n':
return 0;
break;
}
}



return 0;
}
