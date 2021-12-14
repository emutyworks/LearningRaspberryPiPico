#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned int image_png[];
//extern unsigned int image_png_len;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

void pixel(int x, int y, uint16_t c) {
  pico_display.frame_buffer[x + y * 240] = c;
}

int main() {
  pico_display.init();
  pico_display.set_backlight(100);

  while(true) {
    uint16_t c;
    //int r,g,b;
    for(int y=0; y<135; y++) {
      for(int x=0; x<240; x++) {
        c = image_png[x+(y*240)];
        pixel(x, y, c);
        /*
        r = image_png[(x*3)+(y*240*3)];
        g = image_png[(x*3+1)+(y*240*3)];
        b = image_png[(x*3+2)+(y*240*3)];
        c = pico_display.create_pen(r, g, b);
        //pico_display.set_pen(r, g, b);
        //pico_display.pixel(Point(x, y));
        */
      }
    }
    pico_display.update();
  }
  return 0;
}
