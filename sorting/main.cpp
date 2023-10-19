#include <iostream>
#include<vector>
using namespace std;
void median(int arr[],int n)
{
    float x;
    if(n%2==1)
        x=arr[((n+1)/2)-1];
    else
        x=(arr[((n/2)-1)]+arr[(n/2)])/2;
cout<<"the median is >>"<<x<<endl;
}
void modi(int arr[],int l)
{int x=0,y=0,mode;
for(int i=0;i<l-1;i++)
{if(arr[i]==arr[i+1])
        x++;
    else
    {if(x>=y)
    {y=x;
    mode=arr[i];
    x=0;}}
}cout<<"the mode is >>"<<mode<<endl;}
int main()
{
int a,b=0,n;
cout<<"enter the amount"<<endl;
cin>>n;
int t[n];
while(b<n)
{
    cin>>t[b];
    b++;
}
cout<<"{ ";
for(int i=0;i<n;i++)
{
    if(i==n-1)
        cout<<t[i]<<"}";
    else
        cout<<t[i]<<",";
}
cout<<endl;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(t[i]>=t[j])
        {
            a=t[j];
            t[j]=t[i];
            t[i]=a;
        }
    }
}

cout<<"{ ";
for(int i=0;i<n;i++)
{
    if(i==n-1)
        cout<<t[i]<<"}";
    else
        cout<<t[i]<<",";
}
cout<<endl;
modi(t,n);
median(t,n);
return 0;
}
