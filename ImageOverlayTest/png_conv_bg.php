<?php 
$img = imagecreatefrompng("bg_240x135.png");

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