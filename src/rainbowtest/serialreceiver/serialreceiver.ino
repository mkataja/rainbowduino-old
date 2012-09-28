#include <EasyTransfer.h>
#include <Rainbowduino.h>

//create object
EasyTransfer ET;

struct Frame{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  char r[8][8];
  char g[8][8];
  char b[8][8];
};

//give a name to the group of data
Frame frame;

void setup(){
  Serial.begin(19200);
  ET.begin(details(frame), &Serial);
  pinMode(13, OUTPUT);
  Rb.init();
}

void loop(){
  if(ET.receiveData()){   
    for(int x=0; x<8; x++) {
      for(int y=0; y<8; y++) {
        Rb.setPixelXY(x, y, frame.r[x][y], frame.g[x][y], frame.b[x][y]);
      }
    }
  }
}



