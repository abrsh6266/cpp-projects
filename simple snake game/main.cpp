#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
const int height=20,width=20;
int x,y,fruitx,fruity,score;
int ntail,tailx[100],taily[100];
bool gameover;
enum eDirection{UP,DOWN,LEFT,RIGHT,STOP=0};
eDirection dir;
void setup()
{
gameover=false;
x=width/2;
y=height/2;
fruitx=rand()%width;
fruity=rand()%height;
score=0;
dir=STOP;
}
void draw()
{
system("cls");
for(int i=0;i<=width+12;i++)
    cout<<"#";
cout<<endl;
for(int i=0;i<=height;i++)
{
for(int j=0;j<=width+12;j++)
{
    if(j==0)
        cout<<"#";
    if(j==width+11)
        cout<<"#";
    else if(j==x&&i==y)
        cout<<"O";
        else if(j==fruitx&&i==fruity)
            cout<<"F";
    else
    {
    bool print=false;
    for(int a=0;a<ntail;a++)
        {if(i==taily[a]&&j==tailx[a])
        {cout<<"o";
        print=true;}}
    if(!print)
    cout<<" ";
    }

}cout<<endl;
}
for(int i=0;i<=width+12;i++)
    cout<<"#";
cout<<endl;
cout<<"score = "<<score;
}
void input()
{
if(_kbhit())
{
    switch(_getch())
    {
    case 'a':
        dir=LEFT;
        break;
    case 'd':
        dir=RIGHT;
        break;
    case 's':
        dir=DOWN;
        break;
    case 'w':
        dir=UP;
        break;
    case 'x':
        gameover=true;
    }
}
}
void logic()
{
int prevx=tailx[0],prevy=taily[0],prev2x,prev2y;
tailx[0]=x;
taily[0]=y;
for(int a=1;a<ntail;a++)
{
    prev2x=tailx[a];
    prev2y=taily[a];
    taily[a]=prevy;
    tailx[a]=prevx;
    prevy=prev2y;
    prevx=prev2x;
}
for(int a=1;a<ntail;a++)
{
    if(tailx[a]==x&&taily[a]==y)
    gameover=true;
}
    if(x==fruitx&&y==fruity)
    {
        fruitx=rand()%width;
        fruity=rand()%height;
        score+=10;
        ntail++;
    }
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
        break;
    default:
        break;

    }
if(x==-1)
x=width+10;
if(x==width+11)
x=0;
if(y==-1)
y=height;
if(y==height+1)
y=0;
}
int main()
{
setup();
while(!gameover)
{
draw();
input();
logic();
Sleep(80);
}
return 0;
}
