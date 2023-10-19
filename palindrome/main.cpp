#include <iostream>
using namespace std;
int name(int ends,int start,string x)
{if(ends>start)
{if(x[start]==x[ends])
return name(ends-1,start+1,x);
else
return 0;}
else if(ends==start+1||start==ends)
return 1;}
int main()
{cout<<"enter a letter to know whether it is palindome or not"<<endl;
int y;
string x;
getline(cin,x);
y=x.length();
int z=name(y-1,0,x);
if(z)
cout<<"it is palindrome"<<endl;
else
cout<<"no. It is not palindrome."<<endl;
return 0;}
