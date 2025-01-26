#include <stdio.h>
#include <math.h>

int a3, a2, a1, a0;

float func(float x) {
    return (a3 * x * x * x + a2 * x * x + a1 * x + a0);
}

int main() {
    float x0, x1, x2, E, Era;
    printf("Enter coefficients a3, a2, a1, and a0: \n");
    scanf("%d %d %d %d", &a3, &a2, &a1, &a0);
    printf("Enter initial guesses x0, x1 and Error precision: \n");
    scanf("%f %f %f", &x0, &x1, &E);

    // Ensure the initial guesses have opposite signs, otherwise the method won't work.
    if (func(x0) * func(x1) > 0) {
        printf("The Bisection method cannot proceed with these initial guesses.\n");
        return 1;
    }

    while (1) {
        // Midpoint
        x2 = (x0 + x1) / 2;
        
        // Calculate the error
        Era = fabs((x2 - x1) / x2);
        
        if (Era < E) {
            printf("Root = %f\n", x2);
            break;
        }
        
        // Update the interval
        if (func(x0) * func(x2) < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
    }

    return 0;
}

