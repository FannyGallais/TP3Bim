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
  
  image * gargouille = new image;
  gargouille->pix = NULL;
  ppm_read_from_file(gargouille, "gargouille.ppm");
  

  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw
  image * image_bw = new image;
  image_bw->width  = gargouille->width;
  image_bw->height = gargouille->height;
  //image_bw->pix = (u_char*) malloc(3 * gargouille->width * gargouille->height * sizeof(image_bw->pix));
  image_bw->pix = new u_char[3*gargouille->width*gargouille->height];
  
  memcpy(image_bw->pix, gargouille->pix, 3 * gargouille->width * gargouille->height * sizeof(*(image_bw->pix)));

  // Desaturate image_bw
  ppm_desaturate(gargouille);

  // Write the desaturated image into "gargouille_BW.ppm"
  ppm_write_to_file(gargouille,"gargouille_BW.ppm");

  // Free the desaturated image
  delete [] image_bw->pix;
  delete(image_bw);


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  image * image_small = new image;
  image_small->width = gargouille->width;
  image_small->height = gargouille->height;
  image_small->pix = new u_char[3 * image_small->width * image_small->height];
  memcpy(image_small->pix, gargouille->pix, 3 * image_small->width * image_small->height * sizeof(*(image_small->pix)));

  // Shrink image_small size 2-fold
  ppm_shrink(image_small, 2);

  // Write the desaturated image into "gargouille_small.ppm"

  ppm_write_to_file(image_small, "gargouille_small.ppm");


  // Free the not yet freed images

  delete [] image_small->pix;
  delete(image_small);
  delete [] gargouille->pix;
  delete(gargouille);
  return 0;
}





































