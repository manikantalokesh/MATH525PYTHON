#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "trimatrix.h"


static inline double sign(const double x)
{
  if (x<0.0)
    { return -1.0; }
  else
    { return  1.0; }
}

matrix Householder(matrix* R)  // House Holder refelection method
{
  const int N = R->rows;
  assert(N>1); assert(R->cols==N);

  matrix V = new_matrix(N,N);
  vector vtR = new_vector(N);

  for (int k=1; k<=N; k++)
    {
      const int s = N-k+1;
      double normX2 = 0.0;
      for (int i=1; i<=s; i++)
        {
          double tmp = mgetp(R,k-1+i,k);
  	      mget(V,i,k) = tmp;
	        normX2 += pow(tmp,2);
        }
      double x1 = mget(V,1,k);
      mget(V,1,k) += sign(x1)*sqrt(normX2);
      double normV = sqrt(normX2-pow(x1,2)+pow(mget(V,1,k),2));
      for (int i=1; i<=s; i++)
        {	mget(V,i,k) = mget(V,i,k)/normV; }

      for (int i=k; i<=N; i++)
        {
	        vget(vtR,i+1-k) = 0.0;
	        for (int j=1; j<=s; j++)
	          { vget(vtR,i+1-k) += mget(V,j,k)*mgetp(R,j+k-1,i); }
        }

      for (int i=k; i<=N; i++)
	      for (int j=k; j<=N; j++)
	        {
	          mgetp(R,i,j) -= 2.0*mget(V,i+1-k,k)*vget(vtR,j+1-k);
	        }
    }

  delete_vector(&vtR);
  return V;
}

matrix QRdecomp(matrix* R)
{
  const int N = R->rows;
  assert(N>1); assert(R->cols==N);

  matrix V = Householder(R);

  matrix Q = new_matrix(N,N);
  for (int i=1; i<=N; i++)
    { mget(Q,i,i) = 1.0; }

  for (int k=N; k>=1; k--)
    {
      int s = N-k+1;

      for (int i=1; i<=N; i++)
        {
	        double dotprod = 0.0;
 	        for (int ell=1; ell<=s; ell++)
 	          { dotprod += mget(V,ell,k)*mget(Q,ell+k-1,i); }

	        for (int j=k; j<=N; j++)
	          {
	            mget(Q,j,i) -= 2.0*mget(V,j+1-k,k)*dotprod;
	          }
        }
    }

  return Q;
}



void QRDecomp(trimatrix* T, int max_iters, double tol)
{
  // ORdecomp function declaration
  matrix QRdecomp(matrix* A);

  // get size matrix
  const int N = T->rows; assert(N==T->cols);

  int i = 0; //count iterations
  double res = 1.0;  // res temporary variable to stop the loop

  while (res > tol && i < max_iters)
  {
    // Copy tridiagonal matrix into a bigger
    // matrix -- needed for QR step
    matrix R = new_matrix(N,N);
    mget(R,1,1) = tget(T,1,1);
    mget(R,1,2) = tget(T,1,2);
    for (int i=2; i<=(N-1); i++)
    {
      mget(R,i,i-1) = tget(T,i,i-1);
      mget(R,i,i)   = tget(T,i,i);
      mget(R,i,i+1) = tget(T,i,i+1);
    }
    mget(R,N,N-1) = tget(T,N,N-1);
    mget(R,N,N) = tget(T,N,N);

    // QR factorization on bigger matrix
    matrix Q = QRdecomp(&R);

    // Multiply Q and R in reverse order
    // and store in a new tridiagonal matrix
    delete_trimatrix(T);
    *T = matrix_mult_to_trimatrix(&R,&Q);

    // Compute residual and increment iteration count
    res = 0.0;
    for (int i = 2; i <= N; i++) 
    {
      res += pow(fabs(tget(T, i, i-1)), 2.0);
    }
    res = sqrt(res);
    i++;

    // cleanup
    delete_matrix(&R);
  }
}
