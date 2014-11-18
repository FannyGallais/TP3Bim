#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Image
{
 public :
  //Default constructor
  Image(void);
  //copy constructor
  Image(const Image& model);

  //destructor
  ~Image(void);

  //Accessors
  int getHeight(void) const; 
  int getWidth(void) const;
  u_char * getPix(void) const;


  void ppm_write_to_file(image * im, const char* filename);
  void ppm_read_from_file(image * im, const char* filename);
  void ppm_desaturate(image * im);
  void ppm_shrink(image * im, int factor);

 private :
  int height;
  int width;
  u_char * pix;

};


