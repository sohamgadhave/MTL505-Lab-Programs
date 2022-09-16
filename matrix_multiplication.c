#include<stdio.h>
#include<stdlib.h>

void main() {
  int m, n, p, q, sum = 0;;
  printf("Enter the dimensions of the 1st matrix:\n");
  scanf("%d%d", &m, &n);
  printf("Enter the dimensions of the 2nd matrix\n");
  scanf("%d%d", &p, &q);

  if(n!=p || n < 0 || p < 0 || m < 0 || q < 0) {
    printf("Matrix Multiplication not possible\n");
    exit(0);
  }

  int A[m][n], B[p][q], C[m][q];

  //Initialization
  printf("Enter the 1st matrix\n");
  
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &A[i][j]);

  printf("Enter the 2nd matrix\n");

  for(int i = 0; i < p; i++)
    for(int j = 0; j < q; j++)
      scanf("%d", &B[i][j]);

  for(int i = 0; i < m; i++)
    for(int j = 0; j < q; j++) {
      for(int k = 0; k < n; k++)
        sum = sum + A[i][k] * B[k][j];
      C[i][j] = sum;
      sum = 0;
    }

  printf("The product of A and B is\n");

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < q; j++)
      printf("%d\t", C[i][j]);
    printf("\n");
  }
    
}