
#include<stdio.h>
#define ROWS 20
#define COLUMNS 20

void main() {
    int A[ROWS][COLUMNS], B[COLUMNS][ROWS], n = 0, m = 0, i = 0, j = 0;

    printf("Enter the number of rows and columns:\n");
    scanf("%d", &m);
    scanf("%d", &n);

    printf("Enter the elements of the 2D array\n");

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }

    i = j = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            B[i][j] = A[j][i];
    }

    i = j = 0;

    printf("The transpose of the matrix is :\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d\t", B[i][j]);
        printf("\n");
    }

}
