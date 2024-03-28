#include <stdio.h>
#include <stdbool.h>
#include "tuple.h"


typedef struct tuple {
	double		x;
	double		y;
	double		z;
	double		w;
}		Tuple;

Tuple		vector(double, double, double);
Tuple		addTuples(Tuple, Tuple);
Tuple		subTuples(Tuple, Tuple);
Tuple		negateTuple(Tuple);
Tuple		scalarMultTuple(double, Tuple);
Tuple		scalarDivideTuple(Tuple, double);
double		magnitudeOfVector(Tuple);
Tuple		normalizeVector(Tuple);
double		dotProduct(Tuple, Tuple);



Tuple
tuple(double x, double y, double z, double w)
{
	Tuple		t = {x, y, z, w};
	return t;
}

unsigned int	is_point(Tuple);
unsigned int	is_vector(Tuple);

int
main()
{

	Tuple		a = tuple(4.3, -4.2, 3.1, 1.0);


	printf("Test results:\n");
	printf("a.x = %.2f\n", a.x);
	printf("a.y = %.2f\n", a.y);
	printf("a.z = %.2f\n", a.z);
	printf("a.w = %.2f\n", a.w);
	printf("a is a point: %s\n", is_point(a) ? "true" : "false");
	printf("a is not a vector: %s\n", is_vector(a) ? "false" : "true");

	return 0;
}

typedef struct {
	double		x;
	double		y;
	double		z;
	double		w;
} Tuple;

Tuple
vector(double x, double y, double z)
{
	Tuple		vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 0;
	return vec;
}






Tuple
addTuples(Tuple a, Tuple b)
{
	Tuple		result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return result;
}

int
main()
{

	Tuple		a1 = tuple(3, -2, 5, 1);
	Tuple		a2 = tuple(-2, 3, 1, 0);

	Tuple		result = addTuples(a1, a2);

	printf("Result: (%f, %f, %f, %f)\n", result.x, result.y, result.z, result.w);

	return 0;
}

Tuple
point(double x, double y, double z)
{
	Tuple		t;
	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1.0;
	
		point
			return t;
}

Tuple
subTuples(Tuple a, Tuple b)
{
	Tuple		result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = 0.0;
	
		vector
			return result;
}
int
main()
{

	Tuple		p1 = point(3, 2, 1);
	Tuple		p2 = point(5, 6, 7);

	Tuple		result = subTuples(p1, p2);

	printf("Result: (%f, %f, %f, %f)\n", result.x, result.y, result.z, result.w);

	return 0;
}
Tuple
scalarMultTuple(double scalar, Tuple t)
{
	Tuple		result;
	result.x = scalar * t.x;
	result.y = scalar * t.y;
	result.z = scalar * t.z;
	result.w = scalar * t.w;
	return result;
}

int
main()
{

	a = scalarMultTuple(3.5, a);


	Tuple		scalarDivideTuple(Tuple t, double scalar){
		Tuple		result;
				result.x = t.x / scalar;
				result.y = t.y / scalar;
				result.z = t.z / scalar;
				result.w = t.w / scalar;
				return result;
	}
}
