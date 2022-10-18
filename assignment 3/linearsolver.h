void invert(float *, int);
float *get_pivot_postion(float *, int, int, int);
void print_matrix(float *, int);

void invert(float *A, int dimension) {

  int pivots[dimension], pivot_number = 0, start_row = 0, start_column = 0, current_row = 0;
  float inverse[dimension][dimension];
  
  for(int i = 0; i < dimension; i++)
    pivots[i] = -1;
  //Initializing the inverse matrix as identity
  for(int i = 0; i < dimension; i++)
    for(int j = 0; j < dimension; j++)
      inverse[i][j] = i == j ? 1 : 0;
  
  //Gaussian-Jordan algorithm
  float *position, row, column;
  while(start_row < dimension && start_column < dimension) {
    position = get_pivot_postion(A, dimension, start_row, start_column);
    // printf("\n%f\n", *position);
    if(position == NULL)
      break;
    start_row = (position - A) / dimension;
    start_column = (position - (A + start_row * dimension)) % dimension;
    printf("\nrow = %d and col = %d\n", start_row, start_column);
    // printf("\nrow = %d and col = %d\n", start_row, start_column);

    float pivot = *position, temp1, temp2;
    for(int k = 0; k < dimension; k++) {
      //dividing each entry by the pivot element to make the pivot element 1
      *(A + start_row * dimension + k) = *(A + start_row * dimension + k) / pivot;
      inverse[start_row][k] = inverse[start_row][k] / pivot;
    }

    for(int k = 0; k < dimension; k++) {
      //swapping rows
      temp1 = *(A + start_row * dimension + k);
      *(A + start_row * dimension + k) = *(A + current_row * dimension + k);
      *(A + current_row * dimension + k) = temp1;

      temp2 = inverse[start_row][k];
      inverse[start_row][k] = inverse[current_row][k];
      inverse[current_row][k] = temp2;
    }
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
    }
    // print_matrix(A, dimension);
    pivots[pivot_number] = start_column;
    pivot_number++;
    start_row = start_row + 1;
    start_column = start_column + 1;
  }
  
  print_matrix(inverse, dimension);

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