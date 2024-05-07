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
    return ca;
}

Canvas write_pixel(Canvas ca, unsigned int x, unsigned int y, Color co) {
    unsigned int index = ca.channels * (y * ca.width + x);
    ca.pixels[index] = co.red;
    ca.pixels[index + 1] = co.green;
    ca.pixels[index + 2] = co.blue;
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
    co.red = (255);
    co.green = ca.pixels[index + 1];
    co.blue = ca.pixels[index + 2];
    return co;
}

char *canvas_to_ppm(Canvas ca) {
    const unsigned int HEADER_MAX_LEN = 50;
    char header[HEADER_MAX_LEN];
    sprintf(header, "P3\n%d %d\n255\n", ca.width, ca.height);
    unsigned int hbytes = strlen(header);
    unsigned int num_pixels = ca.width * ca.height;
    unsigned int max_len = hbytes + num_pixels * 12 + num_pixels * 2 + 1;

    char *ppm = (char *)malloc(max_len * sizeof(char)+50);
    if (ppm == NULL) {
        return NULL;
    }
    strcpy(ppm, header);
    char *ptr = ppm + hbytes;
    for (unsigned int i = 0; i < num_pixels; i++) {

        Color color;
        color.red = ca.pixels[i * 3];
        color.green = ca.pixels[i * 3 + 1];
        color.blue = ca.pixels[i * 3 + 2];
        if (color.red < 0)
            color.red = 0;
        if (color.red > 255)
            color.red = 255;
        if (color.green< 0)
            color.green = 0;
        if (color.green > 255)
            color.green = 255;
        if (color.blue < 0)
            color.blue = 0;
        if (color.blue > 255)
            color.blue = 255;
        sprintf(ptr, "%d %d %d ", (int)color.red, (int)color.green, (int)color.blue);
        printf("%d %d %d", (int)color.red, (int)color.green, (int)color.blue); // / math new line after color rgb limit 
        printf(ppm, "\n"); // might hace something close to infinte loop 
        ptr += 1;
    }
    ppm[max_len - 2] = '\n';
    ppm[max_len - 1] = '\0';
    return ppm;
}
