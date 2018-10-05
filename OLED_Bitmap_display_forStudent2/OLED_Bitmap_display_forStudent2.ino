//include library
#include <Wire.h>
#include <SPI.h>
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "animation.h"
#define Logo_width 64
#define Logo_height 64

//設定腳位
SSD1306Wire  display(0x3c, 21, 22);
int i=0;
int btn;
int cur=0,old=0;
//圖片內容

void setup() {
  Serial.begin(115200);//設定包率
 display.init(); //初始化(init)
 
    display.setContrast(255); //數值介於0~255，調整對比

   
}

void loop() { 
   cur = digitalRead(23);
   
   if(old==0&&cur==0){
    for(int i=0; i<=1; i++){
  display.clear();
   display.drawXbm(0,0,Logo_width,Logo_height,idle[i]);
   display.display();
  delay(1000);
    }
    Serial.println("x");
   }
Serial.println("A");

  if(cur==1 && old==0){

  for(int i=0; i<=7; i++){
  display.clear();
   display.drawXbm(0,0,Logo_width,Logo_height,walk[i]);
   display.display();
  delay(100);
  }
    old=cur;
    Serial.println("enter");
  }
  
  else if(old==1&&cur==1){
  for(int i=0; i<=7; i++){
  display.clear();
   display.drawXbm(0,0,Logo_width,Logo_height,walk[i]);
   display.display();
  delay(100);
  }
    cur=old;
    old=0;
        Serial.println("???");
  }
  else old=0;

  //讀取(digitalRead)腳位，判斷是否切換圖片 
  //判斷方式任意，定時切換、按鈕切換等等
}
