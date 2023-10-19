#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int mode(float x[],int y)
{
sort(x,x+y);
float counting=1,max_count=0,the_num;
for(int q=1;q<y;q++)
{
    if(x[q]==x[q-1])
        counting++;
    else
    {
        if(counting>max_count)
        {
            max_count=counting;
            the_num=x[q-1];


        }
        counting=1;
    }

}
if(counting>max_count)
    {max_count=counting;
    the_num=x[y-1];}
cout<<"the mode is : "<<the_num<<endl;
return 0;
}

int main()
{
float a[100];
int b;
cout<<"enter the number of elements in the array"<<endl;
cin>>b;
cout<<"enter each elements in the array"<<endl;
for(int q=0;q<b;q++)
{
    cin>>a[q];
}
mode(a,b);
return 0;
}
