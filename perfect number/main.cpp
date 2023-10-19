#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    vector<int> ab;
    vector<int> z;
    for(int n=3;n<7;n++)
     {
    for(int i=1;i<n;i++)
        {if(n%i==0)
        {
        ab[a]=i;
        a++;
        }}
    for(int j=0;j<ab.size();j++)
        {
            b+=ab[j];
        }
        if(b==n)
        {
            z[c]=n;
            ab.clear();
            c++;
            a=0;
            b=0;
        }
        else
           {ab.clear();
            a=0;
            b=0;}
    }

    return 0;
}
