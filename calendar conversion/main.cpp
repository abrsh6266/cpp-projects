#include <iostream>
#include <string>
#include<fcntl.h>
#include<io.h>
using namespace std;
int main()
{
cout<<"Enter the date like  --23/05/2017--OR --23/tir/2017--"<<endl;
int n;
string line(50,'-');
string d,m,y;
string d1,m1,y1;
getline(cin,d,'/');
getline(cin,m,'/');
getline(cin,y);
if(stoi(y)<=2011)
{
if(2011-stoi(y)%4==0)
n=6;
else
n=5;}
if(stoi(y)>=2011)
{
if(stoi(y)-2011%4==0)
n=6;
else
n=5;}
if(m=="meskerem"||m=="01"||m=="1")
{  if(stoi(d)>=1&&stoi(d)<=20)
     {d1=to_string(stoi(d)+10);
      m1="sep";
      y1=to_string(stoi(y)+7);}
   else if(stoi(d)>=21&&stoi(d)<=30)
     {d1=to_string(stoi(d)-20);
      m1="oct";
      y1=to_string(stoi(y)+7);}
}
if(m=="tikimt"||m=="02"||m=="2")
{
    if(stoi(d)>=1&&stoi(d)<=21)
     {d1=to_string(stoi(d)+10);
      m1="oct";
      y1=to_string(stoi(y)+7);}
   else if(stoi(d)>=21&&stoi(d)<=30)
     {d1=to_string(stoi(d)-21);
      m1="nov";
      y1=to_string(stoi(y)+7);}

}
if(m=="hidar"||m=="03"||m=="3")
{  if(stoi(d)>=1&&stoi(d)<=21)
     {d1=to_string(stoi(d)+9);
      m1="nov";
      y1=to_string(stoi(y)+7);}
   else if(stoi(d)>=22&&stoi(d)<=30)
     {d1=to_string(stoi(d)-21);
      m1="dec";
      y1=to_string(stoi(y)+7);}

}
if(m=="tahisas"||m=="04"||m=="4")
{  if(stoi(d)>=1&&stoi(d)<=22)
     {d1=to_string(stoi(d)+9);
      m1="dec";
      y1=to_string(stoi(y)+7);}
   else if(stoi(d)>=23&&stoi(d)<=30)
     {d1=to_string(stoi(d)-22);
      m1="jan";
      y1=to_string(stoi(y)+8);
      }

}
if(m=="tir"||m=="05"||m=="5")
{  if(stoi(d)>=1&&stoi(d)<=23)
     {d1=to_string(stoi(d)+9);
      m1="jan";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=24&&stoi(d)<=30)
     {d1=to_string(stoi(d)-23);
      m1="feb";
      y1=to_string(stoi(y)+8);}

}
if(m=="yekatit"||m=="06"||m=="6")
{  if(stoi(d)>=1&&stoi(d)<=21)
     {d1=to_string(stoi(d)+8);
      m1="feb";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=22&&stoi(d)<=30)
     {d1=to_string(stoi(d)-21);
      m1="mar";
      y1=to_string(stoi(y)+8);}
}
if(m=="megabit"||m=="07"||m=="7")
{  if(stoi(d)>=1&&stoi(d)<=22)
     {d1=to_string(stoi(d)+10);
      m1="mar";
      y1=to_string(stoi(y)+8);}
if(stoi(d)>=23&&stoi(d)<=30)
     {d1=to_string(stoi(d)-21);
      m1="apr";
      y1=to_string(stoi(y)+8);}

}
if(m=="miyazia"||m=="08"||m=="8")
{  if(stoi(d)>=1&&stoi(d)<=22)
     {d1=to_string(stoi(d)+8);
      m1="apr";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=23&&stoi(d)<=30)
     {d1=to_string(stoi(d)-22);
      m1="may";
      y1=to_string(stoi(y)+8);}

}
if(m=="ginbot"||m=="09"||m=="9")
{  if(stoi(d)>=1&&stoi(d)<=23)
     {d1=to_string(stoi(d)+8);
      m1="may";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=24&&stoi(d)<=30)
     {d1=to_string(stoi(d)-23);
      m1="jun";
      y1=to_string(stoi(y)+8);}
}
if(m=="sene"||m=="10")
{  if(stoi(d)>=1&&stoi(d)<=23)
     {d1=to_string(stoi(d)+13);
      m1="jun";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=24&&stoi(d)<=30)
     {d1=to_string(stoi(d)-23);
      m1="jul";
      y1=to_string(stoi(y)+8);}
}
if(m=="hamle"||m=="11")
{  if(stoi(d)>=1&&stoi(d)<=24)
     {d1=to_string(stoi(d)+13);
      m1="jul";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=25&&stoi(d)<=30)
     {d1=to_string(stoi(d)-24);
      m1="aug";
      y1=to_string(stoi(y)+8);}
}
if(m=="nehasie"||m=="12")
{  if(stoi(d)>=1&&stoi(d)<=25)
     {d1=to_string(stoi(d)+6);
      m1="aug";
      y1=to_string(stoi(y)+8);}
   else if(stoi(d)>=26&&stoi(d)<=30)
     {d1=to_string(stoi(d)-24);
      m1="aug";
      y1=to_string(stoi(y)+8);}
}
if(m=="pagume"||m=="13")

{  if(stoi(d)>=1&&stoi(d)<=n)
     {d1=to_string(stoi(d)+5);
      m1="sep";
      y1=to_string(stoi(y)+8);}}
cout<<line<<endl<<endl;
cout<<"In Ethiopian calendar : "<<d<<" / "<<m<<" / "<<y<<endl<<endl;
cout<<"In Gregorian calendar : "<<d1<<" / "<<m1<<" / "<<y1<<endl<<endl;
cout<<line<<endl;
return 0;}
