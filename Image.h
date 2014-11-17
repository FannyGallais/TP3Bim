
  typedef struct
  {
    int height;
    int width;
    unsigned char * pix;
  }image;

  void ppm_write_to_file(image * im, char* filename);
  void ppm_read_from_file(image * im, char* filename);
  void ppm_desaturate(image * im);
  void ppm_shrink(image * im, int factor);


