#include <iostream>
using namespace std;
float input(float &a,float &b)
{   cout<<"enter the first number: ";
    cin>>a;
    cout<<"enter the second number: ";
    cin>>b;
    return 0;}
float menu(float &a,float &b)
{cout<<"enter the numbers you want to solve"<<endl;
input(a,b);
return 0;}
float sum(float &a,float &b)
{return a+b;}
float sub(float &a,float &b)
{return a-b;}
float multi(float &a,float &b)
{return a*b;}
float division(float &a,float &b)
{return a/b;}
int main()
{
float a,b;
again:
cout<<"select and enter from +,-,* and / operations to perform"<<endl;
while(true)
{
char q;
start:
cin>>q;
switch(q)
{
case '+':
    menu(a,b);
    cout<<a<<" + "<<b<<" = "<<sum(a,b)<<endl;
    break;
case '-':
    menu(a,b);
    cout<<a<<" - "<<b<<" = "<<sub(a,b)<<endl;
    break;
case '*':
    menu(a,b);
    cout<<a<<" * "<<b<<" = "<<multi(a,b)<<endl;
    break;
case '/':
    menu(a,b);
    cout<<a<<" / "<<b<<" = "<<division(a,b)<<endl;
    break;
default:
    cout<<"you entered wrong operator try another"<<endl;
    goto start;
    break;}
again2:
cout<<"you want to continue?Y/N"<<endl;
char x;
cin>>x;
if(x=='n'||x=='N')
{cout<<"good bye :("<<endl;
return 0;}
 else if(x=='y'||x=='Y')
goto again;
else
{cout<<"incorrect key!!please enter the correct one"<<endl;
goto again2;}
   }
return 0;}
