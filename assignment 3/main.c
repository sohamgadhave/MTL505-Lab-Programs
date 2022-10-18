#include <stdio.h>
#include "linearsolver.h"

int n;

void main() {
  printf("Enter the dimension of the coefficient matrix A:\n");
  scanf("%d", &n);
  float A[n][n], b[n];
  printf("Enter the coefficient matrix A: \n");
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%f", &A[i][j]);
  printf("Enter the constant matrix b: \n");
  for(int i = 0; i < n; i++)
    scanf("%f", &b[i]);
  int result = solve(A, b, n);
  if(result == 0)
    printf("Unique Solution.\n");
  else if(result == 1)
    printf("Infinte Solutions.\n");
  else
    printf("No Solution.\n");
}