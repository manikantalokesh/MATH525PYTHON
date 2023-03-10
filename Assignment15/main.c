#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include "matrix.h"
#include "trimatrix.h"

int main()
{
  srand( time(NULL) );
  int N;
  printf("    Enter the square matrix size N: ");
  scanf("%i",&N);
  assert(N>1);

  matrix M = original_matrix(N);
  // Hessenberg reduction to tridiagonal form
  trimatrix T = new_trimatrix(N);
  void Hessenberg(const matrix* M, trimatrix* T);
  Hessenberg(&M,&T);
  printf("\n");
  printf("Original Matrix:\n");
  print_matrix(&M);
  printf("Reduction to Tridiagonal Form:\n");
  print_trimatrix(&T);
  // QR Algorithm to find eigenvalues of T
  // which are the same as the eigenvalues of A
  void QRDecomp(trimatrix* T, int max_iters, double tol);
  QRDecomp(&T, 500, 10e-9);
  printf("After QR Algorithm:\n");
  print_trimatrix(&T);
  printf("\nEigenvalues:\n");
  for (int i = 1; i <= N; i++)
 {
   printf("%11.5e\n", tget(&T, i, i));
  
  }
}

