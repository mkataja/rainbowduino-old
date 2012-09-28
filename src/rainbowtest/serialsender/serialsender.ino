#include <EasyTransfer.h>

//create object
EasyTransfer ET;

struct Frame{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  unsigned char r[8][8];
  unsigned char g[8][8];
  unsigned char b[8][8];
};

Frame frame;

void setup(){
  Serial.begin(19200);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(frame), &Serial);

  pinMode(13, OUTPUT);

  randomSeed(analogRead(0));
}

void loop(){
  for(int i=0; i<1157561; i+=6) {
    for(int x=7; x>=0; x--) {
      for(int y=7; y>0; y--) {
        frame.r[x][y] = frame.r[x][y-1];
        frame.g[x][y] = frame.g[x][y-1];
        frame.b[x][y] = frame.b[x][y-1];
      }
    }
    for(int x=7; x>0; x--) {
      frame.r[x][0] = frame.r[x-1][0];
      frame.g[x][0] = frame.g[x-1][0];
      frame.b[x][0] = frame.b[x-1][0];
    }
    
    double joystickX = analogRead(0)/1023.0;
    double joystickY = analogRead(1)/1023.0;
    frame.r[0][0] = 255*joystickX;
    frame.g[0][0] = 255*joystickY;
    frame.b[0][0] = 255*(0.5*joystickX+0.5*(1-joystickY));

    ET.sendData();
  }
}


