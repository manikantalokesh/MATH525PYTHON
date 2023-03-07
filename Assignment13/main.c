#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main() {
  
  matrix M = new_matrix(4,4);
  srand(time(NULL));

  for(int i=1; i <=4; i++ )
    {
    for (int j=1; j <=4; j++ )
        {   
            mget(M,i,j) = 1.0*(i==j) 
            + ((double)rand() / RAND_MAX)*(i >j) + 0.0*(j-1==i);

        }
    }
  printf("M:\n");
  print_matrix(&M);

  matrix M_T = matrix_transpose(&M);
  printf("M_transpose:\n");
  print_matrix(&M_T);

  matrix LOKESH = matrix_mult(&M, &M_T);
  printf("LOKESH:\n");
  print_matrix(&LOKESH);

  // Generate random vector b of length n with entries between 0 and 1
  vector b = new_vector(5);
  printf("b:\n");
  print_vector(&b);

  // Calculate Ax=b using Gaussian partial pivoting
  vector x = solve(&LOKESH, &b);
  printf("x:\n");
  print_vector(&x);

    return 0;
}