#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Image
{
 public :
  void ppm_write_to_file(image * im, const char* filename);
  void ppm_read_from_file(image * im, const char* filename);
  void ppm_desaturate(image * im);
  void ppm_shrink(image * im, int factor);

 private :
  int height;
  int width;
  u_char * pix;

};


