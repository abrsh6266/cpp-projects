#include <iostream>

using namespace std;
float add(float &x,float &y)
{
    return x+y;
}
float sub(float &x,float &y)
{

return x-y;
}
float multi(float &x,float &y)
{
    return x*y;
}
float div(float &x,float &y)
{
    return x/y;
}
void menu(float &x,float&y)
{
start:
    cout<<"select and enter from +,-,* and / operations to perform"<<endl;
{
char q;
cin>>q;
switch(q)
{
case '+':
cout<<x<<" + "<<y<<" = "<<add(x,y)<<endl;
    break;
case '-':
cout<<x<<" - "<<y<<" = "<<sub(x,y)<<endl;
    break;
case '*':
cout<<x<<" * "<<y<<" = "<<multi(x,y)<<endl;
    break;
case '/':
    cout<<x<<" / "<<y<<" = "<<div(x,y)<<endl;
    break;
default:
    cout<<"you entered wrong operator try another"<<endl;
    goto start;
    break;}
}}
void accept()
{
cout<<"enter two numbers to solve an operation"<<endl;
float x,y;
cin>>x>>y;
menu(x,y);
}
int main()
{
again:
while(true)
{
accept();
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
}return 0;
}
