#include <stdio.h>
#include <stdbool.h> // For boolean type
#include "tuple.h"

// Define the Tuple structure
/// @brief 
typedef struct tuple {
    double x;
    double y;
    double z;
    double w;
} Tuple;

Tuple vector(double, double, double);
Tuple addTuples(Tuple, Tuple);
Tuple subTuples(Tuple, Tuple);
Tuple negateTuple(Tuple);
Tuple scalarMultTuple(double, Tuple);
Tuple scalarDivideTuple(Tuple, double);
double magnitudeOfVector(Tuple);
Tuple normalizeVector(Tuple);
double dotProduct(Tuple, Tuple);


// Function to create a tuple
Tuple tuple(double x, double y, double z, double w) {
    Tuple t = {x, y, z, w};
    return t;
}

unsigned int is_point(Tuple);
unsigned int is_vector(Tuple);

int main() {
    
    Tuple a = tuple(4.3, -4.2, 3.1, 1.0);

    
    printf("Test results:\n");
    printf("a.x = %.2f\n", a.x);
    printf("a.y = %.2f\n", a.y);
    printf("a.z = %.2f\n", a.z);
    printf("a.w = %.2f\n", a.w);
    printf("a is a point: %s\n", is_point(a) ? "true" : "false");
    printf("a is not a vector: %s\n", is_vector(a) ? "false" : "true");

    return 0;
    

typedef struct {
    double x;
    double y;
    double z;
    double w;
} Tuple;

Tuple vector(double x, double y, double z) {
    Tuple vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    vec.w = 0; // Since it's a vector, set w to 0
    return vec;
}

bool is_point(Tuple t) {
    return t.w == 1;
}

bool is_vector(Tuple t) {
    return t.w == 0;
}


    // Test case
    Tuple a = vector(4, -4, 3);

    printf("Testing vector create:\n");
    printf("a.x = %f\n", a.x);
    printf("a.y = %f\n", a.y);
    printf("a.z = %f\n", a.z);
    printf("a.w = %f\n", a.w);

    printf("Is a point? %s\n", is_point(a) ? "true" : "false");
    printf("Is a vector? %s\n", is_vector(a) ? "true" : "false");

    return 0;
Tuple addTuples(Tuple a, Tuple b) {
    Tuple result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

int main() {
    // Test case
    Tuple a1 = tuple(3, -2, 5, 1);
    Tuple a2 = tuple(-2, 3, 1, 0);

    Tuple result = addTuples(a1, a2);

    printf("Result: (%f, %f, %f, %f)\n", result.x, result.y, result.z, result.w);

    return 0;

Tuple point(double x, double y, double z) {
    Tuple t;
    t.x = x;
    t.y = y;
    t.z = z;
    t.w = 1.0; // Setting w to 1 for a point
    return t;
}

Tuple subTuples(Tuple a, Tuple b) {
    Tuple result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = 0.0; // Setting w to 0 for a vector
    return result;
    int main() {
    // Test case
    Tuple p1 = point(3, 2, 1);
    Tuple p2 = point(5, 6, 7);

    Tuple result = subTuples(p1, p2);

    printf("Result: (%f, %f, %f, %f)\n", result.x, result.y, result.z, result.w);

    return 0;
    }
}

