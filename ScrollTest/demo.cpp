#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pico_display.hpp"

using namespace pimoroni;

extern unsigned int image_obj1[];
extern unsigned int image_obj2[];
extern unsigned int image_bg1[];
extern unsigned int image_bg2[];
extern unsigned int image_bg3[];
extern unsigned int image_bg4[];
extern unsigned int image_bg5[];

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

void drawObj(unsigned int *obj, int px, int py, int width, int height){
  uint16_t c;
  for(int y=0; y<height; y++){
    for(int x=0; x<width; x++){
      c = obj[x + y * width];
      if(c != 16648){
        pico_display.frame_buffer[(px + x) + ((py + y) * 240)] = c;
      }
    }
  }
  //Treat this color as transparent:
  //c = 16648 = 0b100000100001000 <- ( bit color) r=8,g=8,b=8
}

void scrollBg(unsigned int *bg, int sp, int height, int offset){
  uint16_t c;
  int sx = 0;
  for(int sy=0; sy<height; sy++){
    for(int dx=sp; dx<240; dx++){
      c = bg[dx + sy * 240];
      if(c != 16648){
        pico_display.frame_buffer[sx + (sy + offset) * 240] = c;
      }
      sx++;
    }
    for(int dx=0; dx<sp; dx++){
      c = bg[dx + sy * 240];
      if(c != 16648){
        pico_display.frame_buffer[sx + (sy + offset) * 240] = c;
      }
      sx++;
    }
    sx = 0;
  }
}

int main() {
  pico_display.init();
  pico_display.set_backlight(140);

  int bg1_update_speed = 2;
  int bg1_update_cnt = 0;
  int bg1_sp = 0;
  int bg2_sp = 0;
  int bg45_sp = 0;
  while(true){
    scrollBg(image_bg1, bg1_sp, 64, 37);
    if(bg1_update_cnt == bg1_update_speed){
      bg1_sp++;
      bg1_update_cnt = 0;
    }
    else{
      bg1_update_cnt++;
    }
    scrollBg(image_bg2, bg2_sp, 16, 23);
    scrollBg(image_bg2, bg2_sp, 16, 100);
    bg2_sp++;
    scrollBg(image_bg4, bg45_sp, 14, 8);
    scrollBg(image_bg5, bg45_sp, 16, 118);
    bg45_sp+=2;
    scrollBg(image_bg3, 0, 16, 0);
    drawObj(image_obj1, 50, 65, 39, 22);
    drawObj(image_obj2, 130, 55, 97, 40);
    pico_display.update();
    if(bg1_sp == 240){
      bg1_sp = 0;
    }
    if(bg2_sp == 240){
      bg2_sp = 0;
    }
    if(bg45_sp == 240){
      bg45_sp = 0;
    }
  }
  return 0;
}
