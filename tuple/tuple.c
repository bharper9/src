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