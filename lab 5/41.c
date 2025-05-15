#include <stdio.h>
float f(float x, float y) {
    return x + y;
}
int main() {
    float x0, y0, h, xn, k1, k2, k3, k4;
    printf("Enter initial x, y, step size h, and final x: ");
    scanf("%f%f%f%f", &x0, &y0, &h, &xn);

    while (x0 < xn) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        y0 += (k1 + 2*k2 + 2*k3 + k4)/6;
        x0 += h;
    }

    printf("Approximate solution y(%.2f) = %.4f\n", x0, y0);
    return 0;
}
