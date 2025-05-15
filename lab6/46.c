#include <stdio.h>
#include <math.h>
#define N 5
#define MAX_ITER 1000
#define TOL 0.001

int main() {
    float u[N][N] = {0}, u_old[N][N];
    int i, j, iter = 0;
    float error, h = 1.0;

    // Boundary condition: top = 100
    for (j = 0; j < N; j++)
        u[0][j] = 100;

    do {
        error = 0;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                u_old[i][j] = u[i][j];

        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                float fxy = -4; // Example source term
                u[i][j] = 0.25 * (u_old[i + 1][j] + u_old[i - 1][j] +
                                  u_old[i][j + 1] + u_old[i][j - 1] - h * h * fxy);
                if (error < fabs(u[i][j] - u_old[i][j]))
                    error = fabs(u[i][j] - u_old[i][j]);
            }
        }
        iter++;
    } while (error > TOL && iter < MAX_ITER);

    printf("Poisson solution after %d iterations:\n", iter);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%6.2f ", u[i][j]);
        printf("\n");
    }

    return 0;
}
