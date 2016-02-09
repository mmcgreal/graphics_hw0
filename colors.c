#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>


int main() {

  int fd1 = 0;
  int xres = 500;
  int yres = 500;
  int r = 0;
  int b = 0;
  int g = 0;

  int x;
  int y;
  int z=0;

  fd1 = open("myimage.ppm", O_CREAT|O_WRONLY, 0644);

  //Write the header
  char* header = "P3 500 500 255 ";
  write(fd1, header, 256);
 

    for (y = 0; y < xres; y++) {
        z++;
      for (x = 0; x < yres; x++) {
        r = (z * z + x * y) % 256;
        g = (2 * x + 3 * y) % 256;
        b = (x * x + y * z) % 256;
    
        dprintf(fd1, "%d %d %d ", r, b, g);
      }
  }
     
    
  

  close(fd1);
  return 0;

}




