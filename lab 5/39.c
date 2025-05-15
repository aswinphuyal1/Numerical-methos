#include <stdio.h>
float f(float x, float y) {
    return x + y;
}
int main() {
    float x0, y0, h, xn, yn;
    printf("Enter initial x, y, step size h, and final x: ");
    scanf("%f%f%f%f", &x0, &y0, &h, &xn);

    while (x0 < xn) {
        y0 = y0 + h * f(x0, y0);
        x0 += h;
    }

    printf("Approximate solution y(%.2f) = %.4f\n", x0, y0);
    return 0;
}
