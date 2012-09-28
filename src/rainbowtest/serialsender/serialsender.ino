#include <EasyTransfer.h>

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

PIXEL pixel;
int r[8][8], g[8][8], b[8][8];

void setup(){
  Serial.begin(9600);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(pixel), &Serial);

  pinMode(13, OUTPUT);

  randomSeed(analogRead(0));
}

void loop(){
  for(int i=0; i<1157561; i+=6) {
    for(int x=7; x>=0; x--) {
      for(int y=7; y>0; y--) {
        r[x][y] = r[x][y-1];
        g[x][y] = g[x][y-1];
        b[x][y] = b[x][y-1];
      }
    }
    for(int x=7; x>0; x--) {
      r[x][0] = r[x-1][0];
      g[x][0] = g[x-1][0];
      b[x][0] = b[x-1][0];
    }

    r[0][0] = 128 + 127*sin(i%73/73.0 * 2*3.14159);
    g[0][0] = 128 + 127*sin(i%157/157.0 * 2*3.14159 + 2);
    b[0][0] = 128 + 127*sin(i%101/101.0 * 2*3.14159 + 4);

    for(int x=0; x<8; x++) {
      for(int y=0; y<8; y++) {
        pixel.x = x;
        pixel.y = y;
        pixel.r = r[x][y];
        pixel.g = g[x][y];
        pixel.b = b[x][y];
        ET.sendData();
      }
    }
    delay(50);
  }
}

