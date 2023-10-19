#include <iostream>

using namespace std;

struct date
{
   int day;
   int month;
   int year;
}today[10];


int main()`
{

   for(int i=0;i<10;i++)
   {cin>>today[i].day;
    cin>>today[i].month;
    cin>>today[i].year;
    break;
   }
cout<<today[0].year;

return 0;
}
