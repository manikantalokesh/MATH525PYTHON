#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main()
{
  // New Matrix and Vector
  matrix A = new_matrix(3,3);
  vector v = new_vector(3);

  // Set values
  mget(A,1,1) = 2.0;
  mget(A,1,2) = 1.0;
  mget(A,1,3) = 1.0;
  mget(A,2,1) = 4.0;
  mget(A,2,2) = 3.0;
  mget(A,2,3) = 1.0;
  mget(A,3,1) = 1.0;
  mget(A,3,2) = 1.0;
  mget(A,3,3) = 4.0;

  vget(v,1) = 1.0;
  vget(v,2) = 1.0;
  vget(v,3) = 1.0;

  // Print Matrix and Vector
  print_matrix(&A);
  print_vector(&v);
  
  // set Mu value
  //double Mu = 2.0e0;
 
  // Find largest eigenvalue
  double lambda1 = PowIter(&v,1e-9,500, &A);
  printf("\n Largest Eigenvalue by Power Iteration Method: %.10f\n", lambda1);


  v = Shifted_Inv_power_iteration(&v, 2.0, 1e-9, 500, &A);
  
  double lambda2 = RQiter(&v,1e-9,500, &A);
  printf("\n Smallest Eigenvalue by RayleighsQuotient %.10f\n", lambda2);

  // Cleanup
  delete_matrix(&A);
  delete_vector(&v);
}
