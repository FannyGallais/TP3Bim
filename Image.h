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

  //Getters
  int getHeight(void) const; 
  int getWidth(void) const;
  u_char * getPix(void) const;

  //Writes the image into a file called filename.ppm
  void ppm_write_to_file(const char* filename);
  
  //reads the information from a ppm file and changes width, height and pix
  void ppm_read_from_file(const char* filename);

  // turnes the original image into a black and white image
  void ppm_desaturate();

  //shrink the image by a given factor
  void ppm_shrink(int factor);

 private :
  int height;
  int width;
  u_char * pix;

};


