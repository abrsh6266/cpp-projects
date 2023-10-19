#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const int width=20,height=20;
int x,y;
enum eDirecton{UP,DOWN,lefT,RIGHT,STOP=0};
bool gameover;
eDirecton dir;
void setup()
{
dir=STOP;
x=width/2;
y=height/2;
gameover = false;

}
void wall()
{
system("cls");
for(int i=0;i<width+12;i++)
{
    cout<<"#";
}
cout<<endl;
for(int i=0;i<width;i++)
{
    for(int j=0;j<width+12;j++)
    {
        if(j==0||j==width+11)
            cout<<"#";
        else if(x==j&&y==i)
            cout<<"O";
        else
            cout<<" ";
    }
    cout<<endl;
}
for(int i=0;i<width+12;i++)
{
    cout<<"#";
}
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
    case 'a':
        dir=lefT;
        break;
    case 's':
        dir=DOWN;
        break;
    case 'd':
        dir=RIGHT;
        break;
    }
}
}
void logic()
{
    if(x<=0)
        dir=RIGHT;
    if(x>=30)
        dir=lefT;
    if(y<=0)
        dir=DOWN;
    if(y>=19)
        dir=UP;
    switch(dir)
    {
    case lefT:
        x--;
    case RIGHT:
        x++;
    case UP:
        y--;
    case DOWN:
        y++;
    }

}
int main()
{
setup();
while(!gameover)
{
    wall();
    input();
    logic();
    Sleep(100);
}
    return 0;
}
