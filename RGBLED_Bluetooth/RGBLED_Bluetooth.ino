/*
 * -Smart Mood Light-
 *
 * author jihoonkimtech (jihoonkimtech@naver.com)
 *      (Republic of Korea)
 * version  V1.0.0
 * date  2020-02-22
*/

// LCD 라이브러리
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// 블루투스 라이브러리
#include <SoftwareSerial.h>
#define bt_tx 6
#define bt_rx 7
SoftwareSerial myBluetooth(bt_tx,bt_rx);
/////////////////////////////////////////////////////////
 
 
#define COLOR_R_PIN 9
#define COLOR_G_PIN 10
#define COLOR_B_PIN 11
 
LiquidCrystal_I2C lcd(0x3F, 16, 2);
// 텍스트 버퍼
char line[33];
 
class RGB
{
  public:
  
  RGB(int r, int g, int b);
  ~RGB();
 
  void draw();
  void setDraw(int r, int g, int b);
 
  int red;
  int green;
  int blue;
 
  void lcdPrint();
};
 
RGB::RGB(int r, int g, int b)
{
  red = r;
  green = g;
  blue = b;
}
 
RGB::~RGB()
{
  
}
 
void RGB::draw()
{
  analogWrite(COLOR_R_PIN, 255-red); 
  analogWrite(COLOR_G_PIN, 255-green);
  analogWrite(COLOR_B_PIN, 255-blue);  
 
  lcdPrint();
}
 
void RGB::setDraw(int r, int g, int b)
{
    red = r;
  green = g;
  blue = b;
 
  draw();
}
 
void RGB::lcdPrint()
{
  memset(line, 0x00, 33);
  sprintf(line, "R%d G%d B%d", red, green, blue);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(line);  
}
 
/////////////////////////////////////////////////////////////
// 객체 선언
 
RGB * rgb = new RGB(200, 0, 0);
RGB rgb2(0, 0, 200);
 
void setup() {
 
  Serial.begin(9600);
  myBluetooth.begin(9600);
  
  lcd.begin();  
  
}
 
String readString;
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
 
void loop() {
 
#if 0
  rgb->draw();
  delay(1000);
 
  rgb->setDraw(0, 255, 0);
  delay(1000);
 
  rgb2.draw();
  delay(1000);
 
  rgb2.setDraw(255, 255, 255);
  delay(1000);  
 
  #endif
 
#if 0
 
  if(myBluetooth.available()) {
    char c = myBluetooth.read();
    Serial.println(c);
  }
 
  delay(700);
  
#endif
 
 
  //expect a string like wer,qwe rty,123 456,hyre kjhg,
  //or like hello world,who are you?,bye!,
  while (myBluetooth.available()) {
    
    delay(10);  //small delay to allow input buffer to fill
    char c = myBluetooth.read();  //gets one byte from serial buffer
    if (c == '\n') {
      break;
    }  //breaks out of capture loop to print readstring
    readString += c; 
  } //makes the string readString  
 
  if (readString.length() > 0) {
    
    Serial.println("" + readString + " " + readString.length()); //prints string to serial port out
 
    String sRed = getValue(readString, ',', 0);
    String sGreen = getValue(readString, ',', 1);
    String sBlue = getValue(readString, ',', 2);
    Serial.println(sRed);
    Serial.println(sGreen);
    Serial.println(sBlue);
 
    int r = sRed.toInt();
    int g = sGreen.toInt();
    int b = sBlue.toInt();
    
 
    /*
    String inString = "";    // string to hold input
    inString = "";    // string to hold input
    inString += (char)readString.charAt(1);
    inString += (char)readString.charAt(2);
    inString += (char)readString.charAt(3);
    int r = inString.toInt();
    Serial.println(r, DEC);
    inString = "";    // string to hold input
    inString += (char)readString.charAt(5);
    inString += (char)readString.charAt(6);
    inString += (char)readString.charAt(7);
    int g = inString.toInt();
    Serial.println(g, DEC);
    inString = "";    // string to hold input
    inString += (char)readString.charAt(9);
    inString += (char)readString.charAt(10);
    inString += (char)readString.charAt(11);
    int b = inString.toInt();
    Serial.println(b, DEC);
    */
 
 
   rgb->setDraw(r, g, b);
    
    readString=""; //clears variable for new input
  }
  
  
}
