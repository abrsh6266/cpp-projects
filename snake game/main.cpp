#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20,height=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100],ntail;
enum eDirection{UP,DOWN,LEFT,RIGHT,STOP=0};
eDirection dir;
void setup()
{
score=0;
dir=STOP;
gameover=false;
x=width/2;
y=height/2;
fruitx=rand()%width;
fruity=rand()%width;
}
void draw()
{
system("cls");
for(int i=0;i<width+13;i++)
cout<<"#";
cout<<endl;
for(int i=0;i<height;i++)
{
for(int j=0;j<width+12;j++)
{
if(j==0)
cout<<"#";
if(j==width+11)
cout<<"#";
if(j==x&&i==y)
    cout<<"O";
if(i==fruity&&j==fruitx)
    cout<<"F";

else
{bool print=false;
for(int a=0;a<ntail;a++)
{
if( tailx[a]==j&&taily[a]==i)
{cout<<"o";
 print=true;}
}
if(!print)
cout<<" ";}
}cout<<endl;}
for(int i=0;i<width+13;i++)
    cout<<"#";
    cout<<endl;
    cout<<"score : "<<score<<endl;

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
    case 'w':
    dir=UP;
    break;
    case 's':
    dir=DOWN;
    break;
    case 'x':
    gameover=true;
    break;
    default:
    break;
    }
}
}
void logic()
{
int prevx=tailx[0],prevy=taily[0];
int prev2x,prev2y;
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

    if(x<=0)
    x=width+11;
    if(x>=width+12)
    x=0;
    if(y<=0)
    y=width;
    if(y>=height)
    y=0;
    for(int a=0;a<ntail;a++)
   {if(x==tailx[a]&&y==taily[a])
        gameover=true;}

    if(x==fruitx&&y==fruity)
{   fruitx=rand()%width;
    fruity=rand()%width;
    score+=10;
    ntail++;}
}
int main()
{
setup();
while(!gameover)
{
    draw();
    input();
    logic();
    Sleep(10);
}

return 0;
}
