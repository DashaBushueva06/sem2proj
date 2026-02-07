#include <stdio.h>
#include <math.h>

int main(){
    const double gamme = 6.6743e-11; // m^3 kg^-1 s^-2
    double m1,m2,r,F;
    printf("\nEnter mass m1 (kg): ");
    scanf("%lf",&m1);
    printf("Enter mass m2 (kg): ");
    scanf("%lf",&m2);
    printf("Enter distance r (m): ");
    scanf("%lf",&r);

    F = gamme * m1*m2/(r*r);
    printf("Gravitational force F = %e N\n", F);
}