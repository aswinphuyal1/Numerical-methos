#include <stdio.h>
float f(float x, float y) {
    return x + y;  // example: dy/dx = x + y
}
float df(float x, float y) {
    return 1 + f(x, y);  // derivative of f(x, y) = x + y is 1 + dy/dx
}
int main() {
    float x0, y0, h, x;
    printf("Enter x0, y0, step size h and x to find y(x): ");
    scanf("%f%f%f%f", &x0, &y0, &h, &x);

    float n = (x - x0) / h;
    for (int i = 0; i < n; i++) {
        y0 = y0 + h * f(x0, y0) + (h * h / 2) * df(x0, y0);
        x0 += h;
    }

    printf("Approximate solution y(%.2f) = %.4f\n", x, y0);
    return 0;
}
