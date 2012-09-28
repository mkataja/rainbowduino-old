#include <EasyTransfer.h>
#include <Rainbowduino.h>

//create object
EasyTransfer ET;

struct PIXEL{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  char x;
  char y;
  char r;
  char g;
  char b;
};

//give a name to the group of data
PIXEL pixel;

void setup(){
  Serial.begin(9600);
  ET.begin(details(pixel), &Serial);
  pinMode(13, OUTPUT);
  Rb.init();
}

void loop(){
  if(ET.receiveData()){   
    Rb.setPixelXY(pixel.x, pixel.y, pixel.r, pixel.g, pixel.b);
  }
}



