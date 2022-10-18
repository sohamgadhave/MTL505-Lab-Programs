float *invert(float *, float *, int);
float *get_pivot_postion(float *, int, int, int);
void print_matrix(float *, int);
int solve(float *, float *, int);

int rank, aug_rank;

float *invert(float *A, float *b, int dimension) {

  int pivots[dimension], pivot_number = 0, start_row = 0, start_column = 0, current_row = 0;
  float inverse[dimension][dimension];
  
  for(int i = 0; i < dimension; i++)
    pivots[i] = -1;
  //Initializing the inverse matrix as identity
  for(int i = 0; i < dimension; i++)
    for(int j = 0; j < dimension; j++)
      inverse[i][j] = i == j ? 1 : 0;
  
  float *position, row, column;

  //Gaussian-Jordan algorithm
  while(start_row < dimension && start_column < dimension) {
    position = get_pivot_postion(A, dimension, start_row, start_column);
    // printf("\n%f\n", *position);
    if(position == NULL)
      break;
    start_row = (position - A) / dimension;
    start_column = (position - (A + start_row * dimension)) % dimension;

    float pivot = *position, temp1, temp2, temp3;
    for(int k = 0; k < dimension; k++) {
      //dividing each entry by the pivot element to make the pivot element 1
      *(A + start_row * dimension + k) = *(A + start_row * dimension + k) / pivot;
      inverse[start_row][k] = inverse[start_row][k] / pivot;
    }

    //dividing a component of the b vector
    b[start_row] = b[start_row] / pivot;

    for(int k = 0; k < dimension; k++) {
      //swapping  two rows of the A and inverse matrix
      temp1 = *(A + start_row * dimension + k);
      *(A + start_row * dimension + k) = *(A + current_row * dimension + k);
      *(A + current_row * dimension + k) = temp1;

      temp2 = inverse[start_row][k];
      inverse[start_row][k] = inverse[current_row][k];
      inverse[current_row][k] = temp2;
    }

    //swapping two components of b vector
    temp3 = b[start_row];
    b[start_row] = b[current_row];
    b[current_row] = temp3;

    start_row = current_row;
    current_row++;
    // printf("\ndimension = %d", dimension);

    for(int i = 0; i < dimension; i++) {
      float multiplier = *(A + i * dimension + start_column);
      for(int j = 0; j < dimension; j++) {
        if(i == start_row)
          break;
        inverse[i][j] = inverse[i][j] - multiplier * inverse[start_row][j]; 
        *(A + i * dimension + j) = *(A + i * dimension + j) - multiplier * *(A + start_row * dimension + j);
      }
      b[i] = i == start_row ? b[i] : b[i] - multiplier * b[start_row];
    }
    // print_matrix(A, dimension);
    pivots[pivot_number] = start_column;
    pivot_number++;
    start_row = start_row + 1;
    start_column = start_column + 1;
  }
  
  rank = current_row;
  return inverse;

}

float *get_pivot_postion(float *A, int dimension, int start_row, int start_column) {
  // float *row;
  for(int j = start_column; j < dimension; j++) {
    for(int i = start_row; i < dimension; i++) {
    // row = (A + i);
      if(*(A + i * dimension + j) != 0) {
        return A + i * dimension + j;
      }
    }
  }
  return NULL;
}

void print_matrix(float *A, int dimension) {
  printf("\n");
  for(int i = 0; i < dimension; i++) {
    for(int j = 0; j < dimension; j++)
      printf("%f\t", *(A + i * dimension + j));
    printf("\n");
  }
}

int solve(float *A, float *b, int dimension) {
  float *inverse = invert(A, b, dimension);
  printf("Rank of the matrix is : %d\n", rank);
  for(int i = 0; i < dimension; i++)
    printf("%f\t", *(b + i));
  printf("\n");
  if(rank == dimension)
    return 0;
  else if(b[rank] == 0)
    return 1;
  else
    return -1;
} 