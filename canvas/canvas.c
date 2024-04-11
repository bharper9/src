#include "canvas.h"
#include <stdlib.h>



Canvas  canvas(unsigned int width ,unsigned int height){
Canvas c;
 c.width = width;
 c.height = height;
 return c;
 
}
Canvas write_pixel(Canvas, unsigned int width, unsigned int height, Color out){
Canvas c;
out.red = 255;
out.green = 0;
out.blue = 0;
return c;
}
Color pixel_at(Canvas, unsigned int width, unsigned int height){


}
char* canvas_to_ppm(Canvas){

}

