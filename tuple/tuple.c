#include <math.h>
#include <CUnit/Basic.h>
#include "tuple.h"

typedef struct {
    double x, y, z, w;
} Tuple;

typedef struct {
    double red, green, blue;
} Color;

Tuple tuple(double x, double y, double z, double w) {
    Tuple t = {x, y, z, w};
    return t;
}

Tuple point(double x, double y, double z) {
    return tuple(x, y, z, 1.0);
}

Tuple vector(double x, double y, double z) {
    return tuple(x, y, z, 0.0);
}

Color color(double red, double green, double blue) {
    Color c = {red, green, blue};
    return c;
}

double magnitudeOfVector(Tuple v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}