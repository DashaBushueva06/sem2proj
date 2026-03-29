#include <stdio.h>

struct Vertex {
    double x, y;
};

struct Rectangle {
    struct Vertex lu, rb;
};

void prunt_Rectangle(struct Rectangle *x) {
    printf("(%lf, %lf) -> (%lf, %lf) ", x->lu.x, x->lu.y, x->rb.x, x->rb.y);
}

int input_Rectangle(struct Rectangle *x) {
    printf("Input coordinats lu and rb: ");
    scanf("%lf %lf", &x->lu.x, &x->lu.y);
    scanf("%lf %lf", &x->rb.x, &x->rb.y);
    return true; 
}

int main() {
    struct Rectangle y;
    input_Rectangle(&y);
    prunt_Rectangle(&y);
}