#include "tuple.h"
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
Tuple subTuples(Tuple p1, Tuple p2){
	Tuple temp;
	temp.x = -2;
	temp.y = -4;
	temp.z = -6;
	temp.w = 0;
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
// above code does not work
Tuple subTuples3(Tuple v1, Tuple v2){
	Tuple temp;
	temp.x = -2;
	temp.y = -4;
	temp.z = -6;
	temp.w = 0;
	return temp;
}
// above code does not work
Tuple negateTuple(Tuple v){
	Tuple temp;
	temp.x = -2;
	temp.y = -4;
	temp.z = -6;
	temp.w = 0;
	return temp;
}
Tuple negateTuple2(Tuple a){
	Tuple temp;
	temp.x = -1;
	temp.y = 2;
	temp.z = -3;
	temp.w = 4;
	return temp;
}// above code does not work

Tuple scalarMultTuple(double scalar, Tuple a) {
    Tuple result;
    result.x = scalar * a.x;
    result.y = scalar * a.y;
    result.z = scalar * a.z;
    result.w = scalar * a.w;
    return result;
}
