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

// Function to create a tuple
Tuple tuple(double x, double y, double z, double w) {
    Tuple t = {x, y, z, w};
    return t;
}

unsigned int is_point(Tuple);
unsigned int is_vector(Tuple);

int main() {
    // Test case
    Tuple a = tuple(4.3, -4.2, 3.1, 1.0);

    // Assertions
    printf("Test results:\n");
    printf("a.x = %.2f\n", a.x);
    printf("a.y = %.2f\n", a.y);
    printf("a.z = %.2f\n", a.z);
    printf("a.w = %.2f\n", a.w);
    printf("a is a point: %s\n", is_point(a) ? "true" : "false");
    printf("a is not a vector: %s\n", is_vector(a) ? "false" : "true");

    return 0;
}