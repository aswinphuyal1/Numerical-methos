#include <stdio.h>
#include <math.h>  // ✅ Add this line to avoid fabs() warnings

#define N 5
#define MAX_ITER 1000
#define TOL 0.001

int main() {
    float u[N][N] = {0}, u_old[N][N];
    int i, j, iter = 0;
    float error;

    // Boundary condition: Top side = 100
    for (j = 0; j < N; j++)
        u[0][j] = 100;

    do {
        error = 0;

        // Copy current values to u_old
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                u_old[i][j] = u[i][j];

        // Update inner points using Laplace formula
        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < N - 1; j++) {
                u[i][j] = 0.25 * (u_old[i + 1][j] + u_old[i - 1][j] +
                                  u_old[i][j + 1] + u_old[i][j - 1]);

                if (error < fabs(u[i][j] - u_old[i][j]))
                    error = fabs(u[i][j] - u_old[i][j]);
            }
        }
        iter++;
    } while (error > TOL && iter < MAX_ITER);

    printf("Solution after %d iterations:\n", iter);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%6.2f ", u[i][j]);
        printf("\n");
    }

    return 0;
}
