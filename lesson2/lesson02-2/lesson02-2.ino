#include "rgbdisplay.h"
#include "Latin_Hiragana_24.h"
#include "NotoSansBold15.h"
#include "NotoSansMonoSCB20.h"

#define latin Latin_Hiragana_24
#define small NotoSansBold15
#define digits NotoSansMonoSCB20

#define c1 0xE73C //white
#define c2 0x18C3  //gray
#define c3 0x9986 //red
#define c4 0x2CAB  //green
#define c5 0xBDEF //gold
#define c6 0xFFFAFA //snow

void setup() {

  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_BLK, OUTPUT);

  digitalWrite(LCD_CS, LOW);
  digitalWrite(LCD_BLK, HIGH);

  lcd.init();
  lcd.setRotation(1);
  lcd.fillScreen(TFT_WHITE);
  
  sprite.createSprite(480,320);
}

void loop()
{
  sprite.fillRect(80,120,320,160,0x9986);//绘制一个矩形
  sprite.fillRect(250,200,40,50,c2);//绘制一个矩形
  sprite.drawLine(80,120,240,20,0x2CAB);//绘制一条线
  sprite.drawLine(240,20,400,120,0x2CAB);//绘制一条线
  sprite.drawCircle(160, 170, 30, c5);//绘制一个圆圈
  sprite.pushSprite(0,0);
}
