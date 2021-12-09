#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned char image_png[];
//extern unsigned int image_png_len;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

int main() {
  pico_display.init();
  pico_display.set_backlight(100);

  while(true) {

    int r,g,b;
    for(int y=0; y<135; y++) {
      for(int x=0; x<240; x++) {
        r = image_png[(x*3)+(y*240*3)];
        g = image_png[(x*3+1)+(y*240*3)];
        b = image_png[(x*3+2)+(y*240*3)];
        
        pico_display.set_pen(r, g, b);
        pico_display.pixel(Point(x, y));
      }
    }
    pico_display.update();
  }
  return 0;
}
