#include <iostream>

using namespace std;

int main()
{
int arr[100],a,b,c=0;
cout<<"enter the amount of numbers you want to store"<<endl;
cin>>b;
cout<<"enter numbers"<<endl;
for(int x=0;x<b;x++)
{
cout<<"enter number "<<x+1<<" : ";
cin>>arr[x];
}
cout<<"the numbers you entered are { ";
for(int x=0;x<b;x++)
{
if(x==b-1)
cout<<arr[x];
else
cout<<arr[x]<<",";
}cout<<"}"<<endl;
for(int x=0;x<b;x++)
{
for(int y=x+1;y<b;x++)
{
if(arr[x]==arr[y])
c++;
}cout<<c;
}
return 0;
}

