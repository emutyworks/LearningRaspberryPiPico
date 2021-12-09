<?php 
$img = imagecreatefrompng("240x135.png");

for($y=0; $y<135; $y++){
  for($x=0; $x<240; $x++){
    
    $rgb = imagecolorat($img, $x, $y);

    $r = ($rgb >> 16) & 0xFF;
    $g = ($rgb >> 8) & 0xFF;
    $b = $rgb & 0xFF;

    printf("%s,%s,%s, ",$r,$g,$b);
  }
  echo "\n";
}

?>
