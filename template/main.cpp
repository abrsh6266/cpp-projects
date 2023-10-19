#include <iostream>
#include<string>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
struct bb
{
    string name;
    int age;
    int id;

}q,d;
int main()
{
string line(50,'-');
fstream ab("abx.txt",ios::ate|ios::in|ios::out);
/*ab<<line<<endl;
cout<<"enter your name"<<endl;
cin>>q.name;
ab<<"name : "<<q.name<<endl;
cout<<"enter your age"<<endl;
cin>>q.age;
ab<<"AGE  : "<<q.age<<endl;
cout<<"enter your ID"<<endl;
cin>>q.id;
ab<<"ID   : "<<q.id<<endl;
cout<<"your data is recorded"<<endl;*/
string l;
for(int x=1;getline(ab,l)&&x<7;x++)
{
    if(x==3)
        cout<<l;

}
/*while(ab)
{
ab.get(ch);
cout<<ch;
}*/}
/*struct m
    {
        string name;
        int age;
        int id;
    };
struct k
{
    int x,y,z;
    m stu;
}b={1,2,3};
k q;
k &n=q,*l=&q;
int main()
{
getline(cin,q.stu.name);
    cout<<q.stu.name<<endl;
    cout<<n.stu.name<<endl;
    cout<<l->stu.name;
    return 0;
}*/
/*int x(string n,int b,int a=0)
{
    if(a==b||a+1==b)
        return 1;
    else
    {
        if(n[a]==n[b-1])
            return x(n,b-1,a+1);
    else
        return 0;
    }
}
int main()
{
    string z;
    getline(cin,z);
    int a=z.length();
    int m=x(z,a);
    if(m)
        cout<<"it is palindrome";
    else
        cout<<"it is not palindrome";
        return 0;



}*/



/*int maxi(int a[],int n)
{
    if(n==0)
        return a[0];
    return (a[n-1]>=maxi(a,n-1))?maxi(a,n-1):a[n-1];
}
int main()
{
    int a[]={2,3,5,1000,1,5,6,2,6,1,4,3,7,833};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxi(a,n);
}*/



/*int findMinRec(int A[], int n)
{
        if (n == 1)
        return A[0];
    return max(A[n-1], findMinRec(A, n-1));
}

int main()
{   int A[] = {1, 4, 45, 6, -50, 10, 2};
    int n = sizeof(A)/sizeof(A[0]);
    cout <<findMinRec(A, n);
    return 0;}*/
/*int fabunacci(int x)
  {
      if(x==0)
        return 0;
      if(x==1)
        return 1;
      else
      {
          return fabunacci(x-1)fabunacci(x-2);
      }
  }
int main()
{
    int n;
    cin>>n;
    for(int x=0;x<n;x++)
    {
        cout<<fabunacci(x)<<",";
    }*/
 /* int a[10]={10,9,8,7,6,5,4,3,2,1};
  int k=a[0];
  for(int b=0;b<10;b++)
  {
      for(int c=b;c<10;c++)
      {
          if(a[b]>=a[c])
            {
                k=a[c];
                a[c]=a[b];
                a[b]=k;
            }
      }

  }
  for(int b=0;b<10;b++)
    cout<<a[b]<<endl;
return 0;
}
j(int t,int n=0)
{
    return t+n;
}



template<class abs>
abs ab(abs z,abs y)
{
    return z+y;
}
template <class ax>
ax ak(ax q,ax z)
{
    return q+z;
}
int main()
{
    cout<<ab<int>(1,2);
    cout<<ak<long>(1,2);
    return 0;
}*/
