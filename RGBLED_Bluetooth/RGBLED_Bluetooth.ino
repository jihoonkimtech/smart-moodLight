/*
 * -Smart Mood Light-
 *
 * author jihoonkimtech (jihoonkimtech@naver.com)
 *      (Republic of Korea)
 * version  V1.1.0
 * date  2020-02-22
*/

#include <Wire.h>
// for bluetooth function
#include <SoftwareSerial.h>
#define BT_TX 6
#define BT_RX 7
SoftwareSerial myBluetooth(BT_TX, BT_RX);
 
//RGB LED pins
#define COLOR_R_PIN 9
#define COLOR_G_PIN 10
#define COLOR_B_PIN 11


// text buffer
char line[33];

//RGB LED CLASS
class RGB_LED
{
  public:
  
  RGB_LED(int red, int green, int blue);
  ~RGB_LED();

  //color writing method
  void drawColor();
  
  //set color method
  void setColor(int red, int green, int blue);

  //color variable (in class)
  int _red;
  int _green;
  int _blue;

};
 
RGB_LED::RGB_LED(int red, int green, int blue)
{
  _red = red;
  _green = green;
  _blue = blue;
}
 
RGB_LED::~RGB_LED()
{
  
}
 
void RGB_LED::drawColor()
{
  analogWrite(COLOR_R_PIN, 255-_red); 
  analogWrite(COLOR_G_PIN, 255-_green);
  analogWrite(COLOR_B_PIN, 255-_blue);  
}
 
void RGB_LED::setColor(int r, int g, int b)
{
  red = r;
  green = g;
  blue = b;
 
  drawColor();
}
 
// create Object 
RGB * rgb = new RGB(200, 0, 0);
RGB rgb2(0, 0, 200);
 
void setup() {

  // communication start
  Serial.begin(9600);
  myBluetooth.begin(9600); 
  
}

// readString
String readString;

// Collect rgb datas in string
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
 
 
  // bluetooth waiting..
  while (myBluetooth.available()) {
    
    delay(10);  //small delay (for fill serial buffer from bluetooth data)
    char c = myBluetooth.read();  //get char from serial buffer
    if (c == '\n') { //end of string
      break; //break out
    }  //breaks out of capture loop to print readstring
    readString += c; //save char in readString variable 
  } 
  //complete make readString
 
  if (readString.length() > 0) { //fill readString?

    //for a test
    Serial.println("" + readString + " " + readString.length()); //prints string to serial port out

    //save string data
    String sRed = getValue(readString, ',', 0);
    String sGreen = getValue(readString, ',', 1);
    String sBlue = getValue(readString, ',', 2);
    //for a test
    Serial.println(sRed);
    Serial.println(sGreen);
    Serial.println(sBlue);

    //save color data in variable
    int r = sRed.toInt();
    int g = sGreen.toInt();
    int b = sBlue.toInt();
 
    //writing RGB LED
   rgb->setColor(r, g, b);

    //clears variable
    readString=""; 
  }
  
  
}
