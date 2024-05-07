#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "../surfaces/sphere.h"
#include "../hits/hits.h"
#include "../ray/ray.h"
#include <stdlib.h>


#include "hits.h"





IRec intersection(double t, Sphere object) {
    IRec i;
    i.t = t;
    i.object = object;
    return i;
}

IRecs intersections(unsigned int count, ...) {
    va_list args;
    va_start(args, count);

    IRecs intersections;
    intersections.count = count;
    intersections.records = malloc(count * sizeof(IRec));

    for (unsigned int i = 0; i < count; i++) {
        intersections.records[i] = va_arg(args, IRec);
    }

    va_end(args);

    return intersections;
}





IRec hit(IRecs intersections) {
    IRec closestIntersection;
    closestIntersection.t = INVALID_T;

    for (size_t i = 0; i < intersections.count; i++) {
        if (intersections.records[i].t >= 0 && (closestIntersection.t == INVALID_T || intersections.records[i].t < closestIntersection.t)) {
            closestIntersection = intersections.records[i];
        }
    }

    return closestIntersection;
}
