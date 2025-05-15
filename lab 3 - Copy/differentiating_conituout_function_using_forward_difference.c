#include <stdio.h>
#include <math.h>
double f(double x) {
    return x*x; // Example: f(x) = x^2
}

int main() {
    double x, h;
    printf("**\tCompiled By Aswin phuyal\t**\n");
    printf("Enter x and h: ");
    scanf("%lf %lf", &x, &h);
    // Compute the derivative using the forward difference formula
    double derivative = (f(x + h) - f(x)) / h;
    printf("f'(x) at x = %.2f is approximately %.6f\n", x, derivative);
    return 0;
}
