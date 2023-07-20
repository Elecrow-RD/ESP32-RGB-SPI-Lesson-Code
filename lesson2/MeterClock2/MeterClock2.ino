#include "rgbdisplay.h"
#include "Latin_Hiragana_24.h"
#include "NotoSansBold15.h"
#include "NotoSansMonoSCB20.h"
#include "time.h"


#define latin Latin_Hiragana_24
#define small NotoSansBold15
#define digits NotoSansMonoSCB20

#define c1 0xE73C //white
#define c2 0x18C3  //gray
#define c3 0x9986 //red
#define c4 0x2CAB  //green
#define c5 0xBDEF //gold
#define c6 0xFFFAFA //snow

int fromTop=64;
int left=50;
int shape_width=370;
int shape_heigth=150;

uint16_t grays[60]={0};
uint16_t lines[11]={0};
int sec=0;
int pos=0;

int digit1=0;
int digit2=0;
int digit3=0;
int digit4=0;

long start=0;
long end=0;
int counter=0;
double fps=0;

char timeHour[3];
char timeMin[3];
char timeSec[3];

void setup() {

  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_BLK, OUTPUT);

  digitalWrite(LCD_CS, LOW);
  digitalWrite(LCD_BLK, HIGH);

  lcd.init();
  lcd.setRotation(1);
  lcd.fillScreen(TFT_WHITE);
  
 
  for(int i=0;i<50;i++)
  {
    grays[i]=sprite.color565(i*5, i*5, i*5);
  }
  
  lines[0]=grays[5]; lines[1]=grays[10]; lines[2]=grays[20]; lines[3]=grays[30]; lines[4]=grays[40]; lines[5]=grays[49];
  lines[6]=grays[40]; lines[7]=grays[30]; lines[8]=grays[20]; lines[9]=grays[10]; lines[10]=grays[5];
  
  
  sprite.createSprite(480,320);
  sprite.setTextDatum(4);
}

void my_fillRectHGrandient(int32_t x, int32_t y, int32_t w, int32_t h, uint32_t color1, uint32_t color2)
{
  int plus_h = 0;
  int plus_w = 0;
  for(plus_h=0; plus_h<=h; plus_h++)
  {
      sprite.drawGradientHLine(x, y+plus_h, w, color1, color2);
  }
}

void draw()
{

  if(counter==0)
  start=millis();
  counter++;
  
  if(counter==100)
  {
    end=millis();
    fps=100/((end-start)/1000.00);
    counter=0;
  }
  sprite.fillSprite(c1);
  
  sprite.fillSmoothRoundRect(left+30,fromTop-20,shape_width-60,shape_heigth,8,c2);
  sprite.fillSmoothRoundRect(left+32,fromTop-18,shape_width-64,shape_heigth,8,c1);
  sprite.fillRect(left+30,fromTop-3,shape_width-60,3,c1);
  sprite.fillRect(left+80,fromTop-21,shape_width-160,4,c1);
  
  
  
  sprite.fillSmoothRoundRect(left-10,fromTop,shape_width+20,shape_heigth,8,c2);   //时间的总体大筐筐
  
  sprite.fillSmoothRoundRect(340,fromTop,100,shape_heigth,8,c3);  //秒数的红色框
  sprite.fillRect(340,fromTop,4,shape_heigth,c1);   //时分框和秒框中间的白色间隔

  //时分框和秒数框之间的黑白色球球
  sprite.fillSmoothCircle(342, fromTop+shape_heigth, 9, c1);
  sprite.fillSmoothCircle(342, fromTop+shape_heigth, 5, c2);
  
  for(int i=0;i<4;i++)
  {
    //时分的渐变格子
    my_fillRectHGrandient(left+(i*72), fromTop+32, 30, 54, TFT_BLACK,grays[2]);
    my_fillRectHGrandient(left+(30)+(i*72), fromTop+32, 30, 54, grays[2],TFT_BLACK);
    
    //时分旁边的白色横线
    for(int j=0;j<11;j++)
    if(j==5)
    sprite.drawLine(left+(45)+(i*73),fromTop+34+(j*5),left+(56)+(i*73),fromTop+34+(j*5),lines[j]);
    else
    sprite.drawLine(left+(48)+(i*73),fromTop+34+(j*5),left+(56)+(i*73),fromTop+34+(j*5),lines[j]);
  }

  //秒数的渐变格子
  my_fillRectHGrandient(356, fromTop+32, 35, 54, TFT_BLACK,grays[2]);
  my_fillRectHGrandient(391, fromTop+32, 35, 54, grays[2],TFT_BLACK);

  //秒数旁边的白色横线
  for(int j=0;j<11;j++)
  if(j==5)
  sprite.drawLine(413,fromTop+34+(j*5),421,fromTop+34+(j*5),lines[j]);
  else
  sprite.drawLine(416,fromTop+34+(j*5),421,fromTop+34+(j*5),lines[j]);
  
  //时分秒底下的线条小框框
  sprite.drawLine(left+23,fromTop+100,left+23,fromTop+110,c1);   //时十竖
  sprite.drawLine(left+23,fromTop+110,left+33,fromTop+110,c1);  //时十横
  
  sprite.drawLine(left+107,fromTop+100,left+107,fromTop+110,c1);   //时个竖
  sprite.drawLine(left+107,fromTop+110,left+97,fromTop+110,c1);  //时个横
  
  sprite.drawLine(left+168,fromTop+100,left+168,fromTop+110,c1);//分十竖
  sprite.drawLine(left+168,fromTop+110,left+178,fromTop+110,c1);//分十横
  
  sprite.drawLine(left+248,fromTop+100,left+248,fromTop+110,c1);//分十竖
  sprite.drawLine(left+248,fromTop+110,left+238,fromTop+110,c1);//分个横
  
  sprite.loadFont(latin);
  sprite.setTextColor(c2,c1);
  sprite.drawString("TIME",205,40);
  sprite.unloadFont(); 
  
  sprite.loadFont(small);
  sprite.setTextColor(c1,c3);
  sprite.drawString("sec",380,fromTop+120);
  
  sprite.setTextColor(c1,c2);
  sprite.drawString("hour",98,fromTop+120);
  sprite.drawString("min",245,fromTop+120);
  
  sprite.setTextColor(c2,c1);
  sprite.drawString("POWER",210,fromTop+175);

  //FPS和进度最大值100%最小值0
  sprite.setTextColor(c4,c1);
  sprite.drawString("100%",350,fromTop+190);    //100%
  sprite.drawString(String(fps),10,310);        //fps
  sprite.setTextColor(c3,c1);
  sprite.drawString("0",92,fromTop+190);        //最小值0
  sprite.unloadFont(); 

  //绿色进度条
  sprite.fillRect(105,fromTop+192,180,6,c4);
  sprite.fillRect(285,fromTop+192,60,6,c2);

  //中间的红色线和箭头
  sprite.fillRect(130,fromTop+225,200,3,c3);
  sprite.fillTriangle(322, fromTop+220, 322, fromTop+226, 335, fromTop+226, c3);
  sprite.fillTriangle(322, fromTop+232, 322, fromTop+226, 335, fromTop+226, c3);

  //中间底下的滚轮框
  sprite.fillSmoothRoundRect(150,fromTop+218,160,16,10,c2);       //框
  sprite.drawRect(160,fromTop+218,120,8,TFT_BLACK);
  my_fillRectHGrandient(171, fromTop+222, 60, 8, TFT_BLACK,c6);   //高亮
  my_fillRectHGrandient(230, fromTop+222, 60, 8, c6,TFT_BLACK);

  for(int i=0;i<11;i++)     //滚动的小轮
  {
    sprite.fillRect(165+(i*10)+pos,fromTop+224,2,4,c2);
  }

  //时分秒显示
  sprite.loadFont(digits);
  sprite.setTextColor(c1,grays[2]);
  sprite.drawString(String(timeHour[0]),left+23,fromTop+60);
  sprite.drawString(String(timeHour[1]),left+25+70,fromTop+60);
  sprite.drawString(String(timeMin[0]),left+26+70+70,fromTop+60);
  sprite.drawString(String(timeMin[1]),left+28+70+70+70,fromTop+60);
  sprite.drawString(timeSec,380,fromTop+60);
  sprite.unloadFont();  

  sprite.pushSprite(0,0);
}

void loop()
{
  draw();
}
