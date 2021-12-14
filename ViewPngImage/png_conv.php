<?php 
$img = imagecreatefrompng("240x135.png");

for($y=0; $y<135; $y++){
  for($x=0; $x<240; $x++){
    
    $rgb = imagecolorat($img, $x, $y);
    $r = ($rgb >> 16) & 0xFF;
    $g = ($rgb >> 8) & 0xFF;
    $b = $rgb & 0xFF;
    //printf("%s,%s,%s, ",$r,$g,$b);

    $r = ($r & 0b11111000);
    $b = ($b & 0b11111000) << 5;
    $g1 = ($g & 0b00011000) << 11;
    $g2 = ($g & 0b11100000) >> 5;
    $g = $g1 | $g2;

    $rgb = $r | $g | $b;
    printf("%d,",$rgb);
  }
  echo "\n";
}

/* test
$r = 249;
$g = 249;
$b = 249;

$r = ($r & 0b11111000);
$b = ($b & 0b11111000) << 5;
$g1 = ($g & 0b00011000) << 11;
$g2 = ($g & 0b11100000) >> 5;
$g = $g1 | $g2;

$rgb = $r | $g | $b;
echo "$rgb\n";

--------------------------------------------
[libraries/pico_graphics/pico_graphics.hpp]
    constexpr Pen create_pen(uint8_t r, uint8_t g, uint8_t b) {
      uint16_t p = ((r & 0b11111000) << 8) |
                  ((g & 0b11111100) << 3) |
                  ((b & 0b11111000) >> 3);

      return __builtin_bswap16(p);

--------------------------------------------
- Bit order
ggbbbbbrrrrrggg

- Result of "__builtin_bswap16(p)"
r=0,g=0,b=249(0b11111001)
0b0001111100000000(7936)

r=0,g=249(0b11111001),b=0
0b1100000000000111(49159)
r=0,g=233(0b11101001),b=0
0b0100000000000111(16391)
r=0,g=241(0b11110001),b=0
0b1000000000000111(32775)
r=0,g=113(0b01110001),b=0
0b1000000000000011(32771)
r=0,g=49 (0b00110001),b=0
0b1000000000000001(32769)
r=0,g=17 (0b00010001),b=0
0b1000000000000000(32768)
r=0,g=129(0b10000001),b=0
0b0000000000000100(4)
r=0,g=161(0b10100001),b=0
0b0000000000000101(5)
r=0,g=169(0b10101001),b=0
0b0100000000000101(16389)
r=0,g=177(0b10110001),b=0
0b1000000000000101(32773)

r=249(0b11111001),g=249,b=0
0b0000000011111000(248)
*/
