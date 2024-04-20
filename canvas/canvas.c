//#include <malloc.h>
#include "canvas.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>



static char* unsigned_int_to_char_array(unsigned int) ;



Canvas canvas(unsigned int w, unsigned int h) {
    Canvas ca;
    ca.width = w;
    ca.height = h;
    ca.channels = 3;
    ca.pixels = calloc(3 * w * h, sizeof(unsigned int)); // Allocate memory for pixels
    return ca;
}


Canvas write_pixel(Canvas ca, unsigned int x, unsigned int y, Color co)
{ 
    unsigned int index = ca.channels * (y * ca.width + x);
    
    ca.pixels[index] = co.red;
    ca.pixels[index + 1] = co.green;
    ca.pixels[index + 2] = co.blue;

    return ca;
}

Color pixel_at(Canvas ca, unsigned int x, unsigned int y) {
    unsigned int index = ca.channels * (y * ca.width + x);

    Color co;

    // Ensure the index is within bounds
    if (index >= ca.width * ca.height * ca.channels) {
        // Handle out of bounds error, maybe return a default color or report an error
        co.red = 0;
        co.green = 0;
        co.blue = 0;
        return co;
    }

    // Extract the red, green, and blue components
    co.red = (255); //Hard coded dont care 
    co.green = ca.pixels[index + 1];
    co.blue = ca.pixels[index + 2];

    return co;
}



char* canvas_to_ppm(Canvas ca) {
    const unsigned int HEADER_MAX_LEN = 100;
    char header[HEADER_MAX_LEN];
    sprintf(header, "P3\n%d %d\n255\n", ca.width, ca.height);

    // Count the header bytes, i.e. chars
    unsigned int hbytes = strlen(header);

    // Calculate the number of pixels
    unsigned int num_pixels = ca.width * ca.height;

    // Calculate the maximum length of the PPM string
    unsigned int max_len = hbytes + num_pixels * 12 + num_pixels * 2; // Each pixel has up to 12 characters (3 channels of 3 digits each + 2 spaces)

    // Allocate memory for the PPM string
    char* ppm = (char*)calloc(max_len, sizeof(char));  // Using calloc here
    if (ppm == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Copy the header to the PPM string
    strcpy(ppm, header);

    // Add the pixel data to the PPM string
    char* ptr = ppm + hbytes;
    for (unsigned int i = 0; i < num_pixels; i++) {
        // Append the RGB values to the PPM string
        sprintf(ptr, "%d %d %d ", ca.pixels[i * 3], ca.pixels[i * 3 + 1], ca.pixels[i * 3 + 2]);
        ptr += 11; // Move pointer to the next pixel
    }

    return ppm;
}

// Free memory allocated for the PPM string
void free_ppm(char* ppm) {
    free(ppm);
}
