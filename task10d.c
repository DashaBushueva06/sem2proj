#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Polynomial {
    int degree;
    double *coeffs;
};

void print_Polynomial(struct Polynomial x) {
    printf("Polynomial (degree %d): ", x.degree);
    for (int i = 0; i <= x.degree; i++) {
        printf("(%.2lf)*x^%d", x.coeffs[i], i);
        if (i < x.degree) printf(" + ");
    }
    printf("\n");
}

int input_Polynomial(struct Polynomial *x) {
    printf("Input degree of polynomial: ");
    scanf("%d", &(*x).degree);
    x->coeffs = (double*)malloc((x->degree + 1) * sizeof(double));
    printf("Input %d real coefficients: ", x->degree + 1);
    for (int i = 0; i <= x->degree; i++) {
        scanf("%lf", &x->coeffs[i]);
    }
    return true; 
}

int main(){
    struct Polynomial y;
    
    if (input_Polynomial(&y)) {
        print_Polynomial(y);}
    free(y.coeffs);
}