#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void input(float arr[],int n)
{
cout<<"store all the elements of an array"<<endl;
for(int i=0;i<n;i++)
{

    cin>>arr[i];
}
cout<<"the elements you stored are >>>   {";
for(int i=0;i<n;i++)
{
    if(i==n-1)
        cout<<arr[i]<<" }"<<endl;
    else
    cout<<arr[i]<<", ";
}
sort(arr,arr+n);
cout<<"in a sorted form >> { ";
for(int i=0;i<n;i++)
{
    if(i==n-1)
        cout<<arr[i]<<" }"<<endl;
    else
    cout<<arr[i]<<", ";
}
}
void mean(float arr[],int n,float &x)
{
float a=0;

for(int i=0;i<n;i++)
{
a++;
x+=arr[i];
}
x=x/a;
cout<<"the mean of the elements is "<<x<<endl;
}
void median(float arr[],int n,float &x)
{
if(n%2==0)
{
    x=(arr[(n-1)/2]+arr[((n-1)/2)+1])/2;
}
else
    x=arr[n/2];
}
void mode(float arr[],int n,float x[])
{
int a=0,b=0,c=0;

for(int i=1;i<n;i++)
{
    if(arr[i-1]==arr[i])
    {
        a++;
    }
    else
    {
        if(b<=a)
        {b=a;
        x[c]=arr[i-1];
        c++;
        a=0;}
    }
}
}


int main()
{
float x;
int n;
cout<<"enter the amount of elements of you want to store in an array"<<endl;
cin>>n;
float arr[n],q[n];
input(arr,n);
mean(arr,n,x);
median(arr,n,x);
cout<<"the median is "<<x<<endl;
mode(arr,n,q);
if(q[n].width()==1)
cout<<"the mode is "<<<<endl;
return 0;
}
