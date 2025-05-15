#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k, max_iter;
    float a[10][10], b[10], x[10] = {0}, x_new[10], sum, tol, error;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix (coefficients and constants):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            scanf("%f", &a[i][j]);
        scanf("%f", &b[i]);
    }

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    for(k = 0; k < max_iter; k++) {
        error = 0;
        for(i = 0; i < n; i++) {
            sum = b[i];
            for(j = 0; j < n; j++) {
                if(i != j)
                    sum -= a[i][j] * x[j];
            }
            x_new[i] = sum / a[i][i];
            error += fabs(x_new[i] - x[i]);
        }

        // Update the old values
        for(i = 0; i < n; i++)
            x[i] = x_new[i];

        if(error < tol)
            break;
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++)
        printf("x[%d] = %.4f\n", i+1, x[i]);

    return 0;
}
