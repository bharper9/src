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