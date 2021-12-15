#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned int image_bg[];
extern unsigned int image_ball[];

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

//void pixel(int x, int y, uint16_t c) {
//  pico_display.frame_buffer[x + y * 240] = c;
//}

void drawBg() {
  uint16_t c;
  for(int i=0; i<(240*135); i++) {
    c = image_bg[i];
    pico_display.frame_buffer[i] = c;
  }
}

void drawBall(int px, int py) {
  uint16_t c;
  for(int y=0; y<32; y++) {
    for(int x=0; x<32; x++) {
      c = image_ball[x + y * 32];
      if(c != 16648){
        pico_display.frame_buffer[(px + x) + ((py + y) * 240)] = c;
      }
    }
  }
  /*
  Treat this color as transparent:
  c = 16648 = 0b100000100001000 <- (24 bit color) r=8,g=8,b=8
  */
}

int main() {
  pico_display.init();
  pico_display.set_backlight(100);

  int px2;
  while(true) {
    px2 = 208;
    for(int px1=0; px1<208; px1++) {
      drawBg();
      drawBall(px1, 43);
      drawBall(px2, 59);
      px2--;
      pico_display.update();
    }
    px2 = 0;
    for(int px1=208; px1>0; px1--) {
      drawBg();
      drawBall(px1, 43);
      drawBall(px2, 59);
      px2++;
      pico_display.update();
    }
  };
  return 0;
}
