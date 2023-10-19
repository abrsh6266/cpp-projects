#include <iostream>
using namespace std;
int recursive(int x)
{
if(x==1||x==0)
    return x;
else
    return recursive(x-1)+recursive(x-2);
}
int fact(int x)
{
    if(x==0)
        return 1;
    else
        return x*fact(x-1);
}
string palindrom(string s,int p,int m)
{
int o=s.length();

}
int main()
{
    int x;
    cin>>x;
    cout<<"the factorial of these number is "<<fact(x)<<endl;
    cout<<"the fabonacci serious of a given number is >>";
    for(int a=0;a<=x;a++)
    cout<<recursive(a)<<" ";
    cout<<endl;
    string s;
    getline(cin,s);

return 0;
}
