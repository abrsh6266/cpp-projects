#include <iostream>
#define ma 100
using namespace std;
int main()
{
again:
cout<<"enter the number of elements to store"<<endl;
int x,arr[ma];
cin>>x;
if(x<0||x>100)
{
cout<<"error!!! please enter the correct number of elements you want to store"<<endl;
goto again;
}


cout<<"enter each elements"<<endl;
for(int a=0;a<x;a++)
{
cout<<"enter element "<<a+1<<":";
cin>>arr[a];
cout<<endl;
}
cout<<"the numbers you entered are {";
for(int a=0;a<x;a++)
{
    cout<<" "<<arr[a]<<" ";
}cout<<"}"<<endl;
float z;
for(int a=0;a<x;a++)
{
    for(int b=1+a;b<x;b++)
    {
        if(arr[a]>arr[b])
        {
            z=arr[a];
            arr[a]=arr[b];
            arr[b]=z;
        }
    }
}

cout<<"the sorted in ascending order of the numbers you entered are {";
for(int a=0;a<x;a++)
{
    cout<<" "<<arr[a]<<" ";
}cout<<"}"<<endl;
return 0;
}
