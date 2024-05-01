#include <CUnit/CUnit.h>   
#include "../tuple/tuple.h"
#include "../ray/ray.h"
#include <math.h>           


Ray ray(Tuple origin, Tuple direction) {
    Ray r;
    r.origin = origin;
    r.direction = direction;
    return r;
}

Tuple position(Ray r, double t) {
   Tuple postion;
   postion.w =1;
   postion.x = r.origin.x+r.direction.x*t;
   postion.y = r.origin.y+r.direction.y*t;
   postion.z = r.origin.z+r.direction.z*t;
  
    return postion;
}

