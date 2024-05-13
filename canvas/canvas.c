#include "canvas.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

Canvas canvas(unsigned int w, unsigned int h) {
    Canvas ca;
    ca.width = w;
    ca.height = h;
    ca.channels = 3;
    ca.pixels = (unsigned int *)malloc(3 * w * h * sizeof(unsigned int));
    memset(ca.pixels, 0, 3 * w * h * sizeof(unsigned int)); 
    return ca;
}


Canvas write_pixel(Canvas ca, unsigned int x, unsigned int y, Color co) {
   
    if (x < ca.width && y < ca.height) {
       
        unsigned int index = (y * ca.width + x) * ca.channels;
        
        
        ca.pixels[index] = co.red;
        ca.pixels[index + 1] = co.green;
        ca.pixels[index + 2] = co.blue;
    } 
    

   
    return ca;
}



Color pixel_at(Canvas ca, unsigned int x, unsigned int y) {
    unsigned int index = ca.channels * (y * ca.width + x);
    Color co;
    if (index >= ca.width * ca.height * ca.channels) {
        
        co.red = 0;
        co.green = 0;
        co.blue = 0;
        return co;
    }
    co.red = ca.pixels[index];
    co.green = ca.pixels[index + 1];
    co.blue = ca.pixels[index + 2];
    return co;
    
}

char* canvas_to_ppm(Canvas c) {
    
    char* ppm = (char*)malloc((c.width * c.height * 12) + 20); 
    
    sprintf(ppm, "P3\n%d %d\n255\n", c.width, c.height);

    int offset = strlen(ppm); 

    
    for (unsigned int i = 0; i < c.height; i++) {
        for (unsigned int j = 0; j < c.width; j++) {
            
            int red = (int)(c.pixels[(i * c.width + j) * c.channels] * 255);
            int green = (int)(c.pixels[(i * c.width + j) * c.channels + 1] * 255);
            int blue = (int)(c.pixels[(i * c.width + j) * c.channels + 2] * 255);

            
            red = red > 255 ? 255 : (red < 0 ? 0 : red);
            green = green > 255 ? 255 : (green < 0 ? 0 : green);
            blue = blue > 255 ? 255 : (blue < 0 ? 0 : blue);

            offset += sprintf(ppm + offset, "%d %d %d ", red, green, blue);
        }
       
        ppm[offset++] = '\n';
    }
printf(ppm, "\n");
    ppm[offset] = '\0';

    return ppm;
}





//printf(ppm, "\n");