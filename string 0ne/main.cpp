#include <iostream>
#include<string.h>
using namespace std;

int main()
{
char a[100];
char b[100];
cout<<"ENTER LINES OF CHARACTER"<<endl;
cin.get(a,100);
int y=0;
for(int z=strlen(a);z>=0;z--)
{
    if(z==strlen(a))
        {b[z]='\0';}
    else
    {b[y]=a[z];
    y++;
    }
}
cout<<a;
cout<<endl<<"THE RIVERSE IS ="<<b<<endl;
if(strcmp(a,b)==0)
cout<<"THEY ARE THE SAME SHIT";
else
    cout<<"THEY ARE NOT";
return 0;
}
