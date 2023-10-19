#include <iostream>

using namespace std;

int main()
{
int d,arr[100];
cout<<"enter the amount of number you want to store in the array : ";
cin>>d;
cout<<"enter each numbers you want to store"<<endl;
for(int a=0;a<d;a++)
{
cout<<"enter number "<<a+1<<": ";
cin>>arr[a];
cout<<endl;
}
cout<<"the numbers you entered are = { ";
for(int a=0;a<d;a++)
{if(a==d-1)
cout<<arr[a];
else
cout<<arr[a]<<",";}
cout<<" }"<<endl;
int temp;
for(int a=0;a<d;a++)
{
for(int b=a+1;b<d;b++)
{
if(arr[a]>arr[b])
{
temp=arr[a];
arr[a]=arr[b];
arr[b]=temp;
}
}
}
cout<<"the sorted order of the array is = { ";
for(int a=0;a<d;a++)
{
if(a==d-1)
cout<<arr[a];
else
cout<<arr[a]<<",";
}cout<<" }"<<endl;
int x;
for(int a=0;a<d;a++)
{
for(int b=0;b<d;b++)
{if(arr[a]==arr[b])
x=arr[b];}
}
cout<<x<<" ";


return 0;
}
