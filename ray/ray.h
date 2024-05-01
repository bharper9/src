#ifndef RAY
#define RAY
#include <math.h>     
#include "../tuple/tuple.h"

typedef struct 
{
    Tuple origin;
    Tuple direction;
} Ray;

Ray ray(Tuple, Tuple);
Tuple position(Ray, double);

#endif