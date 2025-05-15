#include <stdio.h>


float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, x, y;
    int i, iterations;

    printf("Enter initial values (x0 and y0): ");
    scanf("%f%f", &x0, &y0);

    printf("Enter the value of x where you want y(x): ");
    scanf("%f", &x);

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    float h = x - x0;
    y = y0;

   
    for (i = 0; i < iterations; i++) {
        y = y0 + h * f(x0, y);  // Simple one-step Picard
        printf("After iteration %d: y(%.2f) = %.4f\n", i+1, x, y);
    }

    printf("\nApproximate solution at x = %.2f is y = %.4f\n", x, y);
    return 0;
}
