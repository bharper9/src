
#include "canvas.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>

static char    *
unsigned_int_to_char_array(unsigned int);

Canvas
canvas(unsigned int w, unsigned int h)
{
	Canvas		ca;
	ca.width = w;
	ca.height = h;
	ca.channels = 3;
	ca.pixels = calloc(3 * w * h, sizeof(unsigned int));
	return ca;

}

Canvas
write_pixel(Canvas ca, unsigned int x, unsigned int y, Color co)
{

	unsigned int	index = ca.channels * (y * ca.width + x);

	ca.pixels[index] = co.red;
	ca.pixels[index + 1] = co.green;
	ca.pixels[index + 2] = co.blue;

	return ca;
}

Color
pixel_at(Canvas ca, unsigned int x, unsigned int y)
{
	unsigned int	index = ca.channels * (y * ca.width + x);

	Color		co;


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



char	       *
canvas_to_ppm(Canvas ca)
{
	const unsigned int HEADER_MAX_LEN = 100;
	char		header[HEADER_MAX_LEN];
	sprintf(header, "P3\n%d %d\n255\n", ca.width, ca.height);
	unsigned int	hbytes = strlen(header);

	unsigned int	num_pixels = ca.width * ca.height;

	unsigned int	max_len = hbytes + num_pixels * 12 + num_pixels * 2 + 1;

	char	       *ppm = calloc(max_len, sizeof(char));
	
		
			if (ppm == NULL) {
			return NULL;
		}


	strcpy(ppm, header);


	char	       *ptr = ppm + hbytes;
	for (unsigned int i = 0; i < num_pixels; i++) {

		int		red = ca.pixels[i * 3];
		int		green = ca.pixels[i * 3 + 1];
		int		blue = ca.pixels[i * 3 + 2];

		if (red < 0)
			red = 0;
		if (red > 255)
			red = 255;
		if (green < 0)
			green = 0;
		if (green > 255)
			green = 255;
		if (blue < 0)
			blue = 0;
		if (blue > 255)
			blue = 255;


		sprintf(ptr, "%d %d %d ", red, green, blue);
		ptr += 11;



	}

	ppm[max_len - 2] ='\n';
	ppm[max_len - 1] ='\0';

	//free(ptr);

	return ppm;
}
