#include "Image.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
  Image gargouille = Image();
  gargouille.ppm_read_from_file("gargouille.ppm");
  

  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw
  Image image_bw = Image(gargouille);
  memcpy(image_bw.getPix(), gargouille.getPix(), 3 * gargouille.getWidth() * gargouille.getHeight() * sizeof(*(image_bw.getPix())));

  // Desaturate image_bw
  gargouille.ppm_desaturate();

  // Write the desaturated image into "gargouille_BW.ppm"
  gargouille.ppm_write_to_file("gargouille_BW.ppm");


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  Image image_small = Image(gargouille);
  memcpy(image_small.getPix(), gargouille.getPix(), 3 * image_small.getWidth() * image_small.getHeight() * sizeof(*(image_small.getPix())));

  // Shrink image_small size 2-fold
  image_small.ppm_shrink(2);

  // Write the desaturated image into "gargouille_small.ppm"
  image_small.ppm_write_to_file("gargouille_small.ppm");


  return 0;
}





































