#include <stdio.h>
int main() {
    int n, i, j, k;
    float a[10][10], ratio;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<=n; j++)
            scanf("%f", &a[i][j]);

    for(i=0; i<n; i++) {
        ratio = a[i][i];
        for(j=0; j<=n; j++)
            a[i][j] /= ratio;

        for(k=0; k<n; k++) {
            if(k != i) {
                ratio = a[k][i];
                for(j=0; j<=n; j++)
                    a[k][j] -= ratio * a[i][j];
            }
        }
    }

    printf("Solution:\n");
    for(i=0; i<n; i++)
        printf("x[%d] = %.3f\n", i+1, a[i][n]);
    return 0;
}
