#include <iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
int s=0;
string ab;
char adu[100];
getline(cin,ab);
for(int a=ab.length()-1;a>-1;a--)
{adu[s]=ab.at(a);
s++;}
cout<<adu<<endl;
if(-adu==ab)
    cout<<"they are equal";
return 0;
}
