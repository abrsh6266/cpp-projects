#include <iostream>
#include<string>
using namespace std;

int main()
{
string day,month,hourx,minutex,secondx;
int second,minute,hour,year;
cout<<"enter the date time"<<endl;
cout<<"enter the day >>";
getline(cin,day);
cout<<"enter the month >>:";
getline(cin,month);
cout<<"enter the year >>";
cin>>year;
cout<<"enter the time like 09 01 37 (hour,minute,second)"<<endl;
cout<<">>";
cin>>hour>>minute>>second;
if(hour<10)
hourx="0"+to_string(hour);
else
hourx=to_string(hour);
if(minute<10)
minutex="0"+to_string(minute);
else
minutex=to_string(minute);
if(second<10)
secondx="0"+to_string(second);
else
secondx=to_string(second);
system("cls");
if(hour>=6&&hour<12)
{cout<<"the time is >>"<<endl<<day<<" "<<month<<" "<<hourx<<":"<<minutex<<":"<<secondx<<" "<<year<<endl;
cout<<"have a nice morning sir!"<<endl;}
if(hour>=12&&hour<18)
{cout<<"the time is >>"<<endl<<day<<" "<<month<<" "<<hourx<<":"<<minutex<<":"<<secondx<<" "<<year<<endl;
cout<<"have a nice noon sir!"<<endl;}
if(hour>=18)
{cout<<"the time is >>"<<endl<<day<<" "<<month<<" "<<hourx<<":"<<minutex<<":"<<secondx<<" "<<year<<endl;
cout<<"have a nice night sir!"<<endl;}
if(hour<6)
{cout<<"the time is >>"<<endl<<day<<" "<<month<<" "<<hourx<<":"<<minutex<<":"<<secondx<<" "<<year<<endl;
cout<<"have a nice night sir!"<<endl;}
return 0;
}
