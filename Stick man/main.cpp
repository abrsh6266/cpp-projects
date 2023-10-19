#include<graphics.h>

// stickman open legs with rose

void stickman_open(int speed,int color)
{
  int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  line(50+i+s,350,50+i+s,400);
  //legs
  line(50+i+s,400,30+i+s,450);
  line(50+i+s,400,70+i+s,450);
  //left hand
    line(50+s+i,360,20+s+i,400);
  //right hand
    line(50+s,360+i,80+s,400+i);


  }

}

// stickman close legs with rose

void stickman_close(int speed,int color)
{  int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  line(50+i+s,350,50+i+s,400);
  //legs
  line(50-i+s,400,50-i+s,450);
  line(50+i+s,400,50+i+s,450);
  //left hand
    line(50+s+i,360,20+s+i,400);
;
  //right hand
    line(50+s,360+i,80+s,400+i);


  }


}

// stickwomen open legs

void stickwomen_open(int speed,int color)
{
  int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  //dress
  line(50+i+s,350,40+i+s,400);
  line(50+i+s,350,60+i+s,400);
  line(40+s,400-i,60+s,400-i);
  //legs
  line(50+i+s,400,30+i+s,450);
  line(50+i+s,400,70+i+s,450);
  //left hand
    line(50+s+i,350,20+s+i,400);
  //right hand
    line(50+s+i,350,80+s+i,400);


  }

}

//stickman with rose
void stickman_rose(int speed,int color)
{
    int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  line(50+i+s,350,50+i+s,400);
  //legs
  line(50+i+s,400,30+i+s,450);
  line(50+i+s,400,70+i+s,450);
  //left hand
    line(50+s+i,360,20+s+i,400);
  //right hand
    line(50+s,360+i,80+s,380+i);
    line(80+i+s,380,100+i+s,360);

  }
  // rose
  setcolor(LIGHTGREEN);
  for(int i=0;i<2;i++)
  line(100+i+s,360,100+i+s,345);
  setcolor(LIGHTRED);
  for(int i=10,h=0;i>=0;i--,h++)
  {
    line(90+i+s,345-h,110-i+s,345-h);
  }
}

// stickman rose break
void stickman_rose_break(int speed,int color)
{
    int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  line(50+i+s,350,50+i+s,400);
  //legs
  line(50+i+s,400,30+i+s,450);
  line(50+i+s,400,70+i+s,450);
  //left hand
    line(50+s+i,360,20+s+i,400);
  //right hand
    line(50+s,360+i,80+s,380+i);
    line(80+i+s,380,100+i+s,360);

  }
  // rose
  setcolor(LIGHTGREEN);
  for(int i=0;i<2;i++)
    {
    line(100+i+s,360,100+i+s,350);
    line(100+s,350+i,110+s,350+i);
  }
  setcolor(LIGHTRED);
  for(int i=1,h=0;i<=10;i++,h++)
  {
    line(110+s+i,350-i,110+i+s,350+i);
  }
}
// stickwomen close legs

void stickwomen_close(int speed,int color)
{
  int s=speed;

  for(int i=0;i<3;i++)
  {
  setcolor(color);
  circle(50+s,320,30+i);
  //dress
  line(50+i+s,350,40+i+s,400);
  line(50+i+s,350,60+i+s,400);
  line(40+s,400-i,60+s,400-i);
  //legs
  line(50-i+s,400,50-i+s,450);
  line(50+i+s,400,50+i+s,450);
  //left hand
    line(50+s+i,350,20+s+i,400);
  //right hand
    line(50+s+i,350,80+s+i,400);


  }

}

// stickman chat
void stickman_chat(int speed,int box_color,int text_color)
{
  int s=speed;
  setcolor(box_color);

  int points[16]={50+s,280,40+s,270,-40+s,270,-40+s,200,70+s,200,70+s,270,60+s,270,50+s,280};
  drawpoly(8,points);

   setcolor(text_color);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
  outtextxy(-20+s,210,"I Love");
  outtextxy(-5+s,240,"You");

}

void stickwomen_chat(int speed,int box_color,int text_color)
{
  int s=speed;
  setcolor(box_color);

  int points[16]={50+s,280,40+s,270,30+s,270,30+s,200,140+s+50,200,140+s+50,270,60+s,270,50+s,280};
  drawpoly(8,points);
   setcolor(text_color);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
  outtextxy(45+s,210,"Sorry, I love");
  outtextxy(100+s,240,"Raj");

}
// road

void road(int color)
{
  setcolor(color);
  for(int i=0;i<3;i++)
  {
    line(0,450+i,700,450+i);
  }
  setcolor(WHITE);
}

// cloud
void cloud(int speed,int cloud_color)
{setcolor(LIGHTGRAY);
 int a=speed;
    int i=2;
    //up
    arc(50+a,50+2,20,160,25+i);
    arc(100-2+a,50+2,20,160,25+i);
    //down
    arc(50+a,80-4,180+20,360-20,25+i);
    arc(100-2+a,80-4,180+20,360-20,25+i);
      //left
    arc(25+5+a,65,90+10,270-10,20+i);
      // right
    arc(125-5+a,65,270,90,20+i);
