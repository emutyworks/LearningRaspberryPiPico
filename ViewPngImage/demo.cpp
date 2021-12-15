#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned int image_png[];

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

//void pixel(int x, int y, uint16_t c) {
//  pico_display.frame_buffer[x + y * 240] = c;
//}

int main() {
  pico_display.init();
  pico_display.set_backlight(100);

  uint16_t c;
  for(int i=0; i<(240*135); i++) {
    c = image_png[i];
    pico_display.frame_buffer[i] = c;
  }
  pico_display.update();
  while(true) {};

  return 0;
}
