#include <stdio.h>
int main() {
    int i, j, k, n;
    float a[10][10], l[10][10] = {0}, u[10][10] = {0};

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%f", &a[i][j]);

    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            u[i][j] = a[i][j];
            for(k=0; k<i; k++)
                u[i][j] -= l[i][k] * u[k][j];
        }

        l[i][i] = 1;
        for(j=i+1; j<n; j++) {
            l[j][i] = a[j][i];
            for(k=0; k<i; k++)
                l[j][i] -= l[j][k] * u[k][i];
            l[j][i] /= u[i][i];
        }
    }

    printf("L matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%.3f ", l[i][j]);
        printf("\n");
    }

    printf("U matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%.3f ", u[i][j]);
        printf("\n");
    }

    return 0;
    
    
}
