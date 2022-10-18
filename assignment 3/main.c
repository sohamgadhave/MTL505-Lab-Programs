#include <stdio.h>
#include "linearsolver.h"

int n;

void main() {
  printf("Enter the dimension of the coefficient matrix A:\n");
  scanf("%d", &n);
  float A[n][n];
  printf("Enter the coefficient matrix A: \n");
  for(int i = 0; i < n; i++) {
    // float row[n];
    for(int j = 0; j < n; j++) {
      scanf("%f", &A[i][j]);
    }
    // A[i] = row;
  }
  // print_matrix(A, n);
  printf("\nn = %d", n);
  invert(A, n);
}