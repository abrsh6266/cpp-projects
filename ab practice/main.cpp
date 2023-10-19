#include <iostream>
#include<math.h>
#include <iomanip>
using namespace std;
float eqn(float val)
{
    return 3*val + sin(val) - exp(val);
}
float fun(float x,float y,float z,string eq)
{

    float a,b,c,d;
    do
    {
        a=(x+y)/2;
        if(eqn(x)*eqn(a)< 0)
        {
            y=a;
        }
        else
            x=a;
    }while(abs(x-y)>=z);

    return a;
}
float fu(float a)
{
    return (a*a*a)+(a*a)-(3*a)-3;
}
void solve( float number, int place) {
   cout << fixed;
   cout << setprecision( place );
   cout << number << endl;
}
float fun2(float x,float y,float z)
{
    float s;
    if(fu(x)<fu(y))
    {
        s=x;
        x=y;
        y=x;
    }
    do
    {
        s = y-(fu(y)*(x-y)/(fu(x)-fu(y)));
        x=y;
        y=s;
    }while(abs(fu(s))>=z);
    return s;
}
float chk1(float a)
{
    return 3*a+sin(a)- pow(2.718,a);
}
float chk2(float a)
{
    return 3+cos(a)- pow(2.718,a);
}
float newton(float x,float y)
{
    float z,zz=0;
    if(chk1(x)!=0&&chk2(x)!=0)
    {
        do
        {
            z=x;
            x=x-(chk1(x)/chk2(x));
            zz++;
        }while(abs(x-z)>=y);


    }
    cout<<zz<<endl;
    return x;
}
int main()
{
    /*float x,y,z;
    cout<<"add the interval and tolerance value"<<endl;
    cout<<"x = ";cin>>x;
    cout<<"y = ";cin>>y;
    cout<<"tolerance value = ";cin>>z;
    cout<<"interval = (";cout<<x<<",";cout<<y<<") and the tolerance value is "<<z;
    cout<<endl<<"the root is "<<fun(x,y,z,eq);
    cout<<fun2(x,y,z);
    float xxx=chk1(0.3604);
    solve(xxx,12);*/
cout<<log(2.718281828)
 return 0;
}
