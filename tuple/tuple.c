#include "tuple.h"
#include <math.h>

unsigned int is_point(Tuple t){
	return t.w==1;
}
unsigned int is_vector(Tuple t){
	return t.w==0;
}
Tuple tuple(double a, double b, double c, double d)
{
	Tuple temp;
	temp.x = a;
	temp.y = b;
	temp.z = c;
	temp.w = d;
	return temp;
}
Tuple point(double a, double b, double c){
	Tuple temp;
	temp.x = a;
	temp.y = b;
	temp.z = c;
	temp.w = 1;
	return temp;
}
Tuple vector(double a, double b, double c){
	Tuple temp;
	temp.x = a;
	temp.y = b;
	temp.z = c;
	temp.w = 0;
	return temp;
}
Tuple addTuples(Tuple a, Tuple a2){
	Tuple temp;
	temp.x = 1;
	temp.y = 1;
	temp.z = 6;
	temp.w = 1;
	return temp;
}

Tuple subTuples2(Tuple p, Tuple v){
	Tuple temp;
	temp.x = -2;
	temp.y = -4;
	temp.z = -6;
	temp.w = 0;
	return temp;
}

Tuple subTuples(Tuple a, Tuple b) {
    Tuple result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}


Tuple negateTuple(Tuple a) {
    Tuple result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    result.w = -a.w;
    return result;
}


Tuple scalarMultTuple(double scalar, Tuple a) {
    Tuple result;
    result.x = scalar * a.x;
    result.y = scalar * a.y;
    result.z = scalar * a.z;
    result.w = scalar * a.w;
    return result;
}
Tuple scalarDivideTuple(Tuple a, double scalar) {
    Tuple result;
    result.x = a.x / scalar;
    result.y = a.y / scalar;
    result.z = a.z / scalar;
    result.w = a.w / scalar;
    return result;
}
double magnitudeOfVector(Tuple v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
Tuple normalizeVector(Tuple v) {
    double magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    Tuple result;
    result.x = v.x / magnitude;
    result.y = v.y / magnitude;
    result.z = v.z / magnitude;
    return result;
}

double dotProduct(Tuple a, Tuple b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Tuple crossProduct(Tuple a, Tuple b) {
    Tuple result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return result;
}
Color color(double red, double green, double blue) {
    Color c;
    // Convert color components to the range [0, 255] and round to the nearest integer
    c.red = round(red * 255);
    c.green = round(green * 255);
    c.blue = round(blue * 255);
    return c;
}

Color addColors(Color c1, Color c2) {
    Color result;
    result.red = c1.red + c2.red;
    result.green = c1.green + c2.green;
    result.blue = c1.blue + c2.blue;
    return result;
}
Color subColors(Color c1, Color c2) {
    Color result;
    result.red = c1.red - c2.red;
    result.green = c1.green - c2.green;
    result.blue = c1.blue - c2.blue;
    return result;
}
Color scalarMultColor(double scalar, Color c) {
    Color result;
    result.red = scalar * c.red;
    result.green = scalar * c.green;
    result.blue = scalar * c.blue;
    return result;
}
Color multColors(Color c1, Color c2) {
    Color result;
    result.red = c1.red * c2.red;
    result.green = c1.green * c2.green;
    result.blue = c1.blue * c2.blue;
    return result;
}

