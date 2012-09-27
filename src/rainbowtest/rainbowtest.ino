#include <Rainbowduino.h>

void setup()
{
  Rb.init();
}

void getCharMask(unsigned char ascii, int poX, int poY, int** mask)
{
  if((ascii < 0x20)||(ascii > 0x7e))//Unsupported char.
  {
    ascii = '?';
  }
  for(int i=0;i<8;i++)
  {
    int temp = pgm_read_byte(&simpleFont[ascii-0x20][i]);
    for(int f=0;f<8;f++)
    {
      if((temp>>f)&0x01)
      {
        mask[poY+f][poX+i] = 1;
      } else {
        mask[poY+f][poX+i] = 0;
      }
    }
  }
}

int r[8][8], g[8][8], b[8][8];

void loop()
{
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
    
    int charmask = malloc(nrows;
    getCharMask('L', 0, 0, charmask);
    
    // Draw buffers
    Rb.blankDisplay();
    for(int x=0; x<8; x++) {
      for(int y=0; y<8; y++) {
        Rb.setPixelXY(x,y,r[x][y],g[x][y],b[x][y]);
      }
    }
    delay(60);
  }
}


