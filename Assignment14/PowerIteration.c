#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"


double PowIter(vector* v, double Total, int MaxIters, matrix* A)
{
    const int size = v->size;
    assert(size>0);
    assert(size==A->rows); assert(size==A->cols);

    double lambda = 1.0e0;
    double lambda_old = 0.0e0;

    vector v_new = new_vector(size);
    vector w = new_vector(size);

    double mag_v = vector_magnitude(v);
    double mag_w = 1;

  // Set v_new to v with magnitude 1
    for(int i = 1; i<=size; i++)
        { vget(v_new,i) = vgetp(v,i)/mag_v; }

  // Evaluate lambda
    vector Ax = matrix_vector_mult(A, &v_new);
    lambda = vector_dot_mult(&v_new, &Ax);

  // Iterate
    int k = 0;
    int mstop = 0;
    while (k<MaxIters && mstop==0)
    {
        k++;
        w = matrix_vector_mult(A, &v_new);
        mag_w = vector_magnitude(&w);

        // Set w to w with magnitude 1
        for(int i = 1; i<=size; i++)
        { vget(v_new,i) = vget(w,i)/mag_w; }

        // Evaluate lambda
        Ax = matrix_vector_mult(A, &v_new);
        lambda_old = lambda;
        lambda = vector_dot_mult(&v_new, &Ax);

        // Check for convergence
        if (fabs(lambda-lambda_old)<Total)
        {
            mstop = 1;
            printf("\n Eigenvalue converged in %d iterations\n", k);
        }

    }

    return lambda;
}

