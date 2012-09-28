#include <Rainbowduino.h>

void setup()
{
  Rb.init();
  Serial.begin(9600);
}

void loop()
{
  Serial.flush();
  while (Serial.available() < 5) { // Command length is 5 bytes
    // Wait for a command
  }
  int cmd1 = Serial.read();
  int cmd2 = Serial.read();
  int arg1 = Serial.read();
  int arg2 = Serial.read();
  int arg3 = Serial.read();
  
  int x = cmd1 % 7;
  int y = cmd2 % 7;
  int r = arg1;
  int g = arg2;
  int b = arg3;
  Rb.setPixelXY(x, y, r, g, b);
  Serial.println("Ok!");
}


