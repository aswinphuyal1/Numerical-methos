#include <stdio.h>
int main() {
    int i, j, k, n;
    float a[10][20], ratio;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%f", &a[i][j]);

    for(i=0; i<n; i++)
        for(j=n; j<2*n; j++)
            a[i][j] = (i == j-n) ? 1 : 0;

    for(i=0; i<n; i++) {
        ratio = a[i][i];
        for(j=0; j<2*n; j++)
            a[i][j] /= ratio;

        for(k=0; k<n; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j=0; j<2*n; j++)
                    a[k][j] -= ratio * a[i][j];
            }
        }
    }

    printf("Inverse Matrix:\n");
    for(i=0; i<n; i++) {
        for(j=n; j<2*n; j++)
            printf("%.3f ", a[i][j]);
        printf("\n");
    }

    return 0;
}
