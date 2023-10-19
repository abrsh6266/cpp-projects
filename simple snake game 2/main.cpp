#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const int height=20,width=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100],ntail;
bool gameover;
enum eDirection{UP,DOWN,LEFT,RIGHT,STOP=0};
eDirection dir;
void setup()
{
dir=STOP;
gameover=false;
x=width/2;
y=height/2;
fruitx=rand()%width;
fruity=rand()%height;
score=0;
}
void draw()
{
system("cls");
for(int i=0;i<width+12;i++)
    cout<<"#";
    cout<<endl;
for(int i=0;i<height;i++)
{
    for(int j=0;j<width+12;j++)
    {
    if(j==0||j==width+11)
        cout<<"#";
    else if(i==y&&j==x)
        cout<<"O";
    /*else if(i==fruity&&j==fruitx)
        cout<<"F";*/
    else
    {
    /*bool print =false;
    for(int a=0;a<ntail;a++)
    {if(tailx[a]==j&&taily[a]==i)
    {
    cout<<"o";
    print=true;
    }}
    if(!print)
    */cout<<" ";}
    }cout<<endl;
}
for(int i=0;i<width+12;i++)
    cout<<"#";
    cout<<endl;
/*cout<<"score :"<<score;*/
}
void input()
{
if(_kbhit())
{

switch(_getch())
{
case 'w':
dir=UP;
break;
case 's':
dir=DOWN;
break;
case 'd':
dir=RIGHT;
break;
case 'a':
dir=LEFT;
break;
case 'x':
gameover=true;
break;
}
}


}
void logic()
{
    if(x<=1)
        dir=RIGHT;
    if(x>=30)
        dir=LEFT;
    if(y<=0)
        dir=DOWN;
    if(y>=19)
        dir=UP;
/*for(int a=1;a<ntail;a++)
{
if(tailx[a]==x&&taily[a]==y)
    gameover=true;
}
if(x==0)
x=width+10;
if(x==width+11)
x=1;
if(y==-1)
y=width;
if(y==width+1)
y=0;
int prevx=tailx[0],prevy=taily[0];
int prev2y;
int prev2x;
tailx[0]=x;
taily[0]=y;
for(int a=1;a<ntail;a++)
{
prev2x=tailx[a];
prev2y=taily[a];
tailx[a]=prevx;
taily[a]=prevy;
prevx=prev2x;
prevy=prev2y;
}

if(x==fruitx&&y==fruity)
{
score+=10;
fruitx=rand()%width;
fruity=rand()%height;
ntail++;}*/
switch(dir)
{
case UP:
y--;
break;
case DOWN:
y++;
break;
case LEFT:
x--;
break;
case RIGHT:
x++;
default:
break;
}}
int main()
{
setup();
while(!gameover)
{
draw();
input();
logic();
Sleep(70);
}
return 0;}
