#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

//**! Rayleigh QUotataion 
double RayleighQuotation(vector* v, double Total, int MaxIters, matrix* A)
{
    // const int size = v->size;
    // assert(size>0);
    // assert(size==A->rows); assert(size==A->cols);

    // double lambda = 1.0e0;
    // double lambda_old = 0.0e0;
    // vector v_new = new_vector(size);
    // vector w = new_vector(size);
    // matrix Iden = IdentityMatrix(size);
    // matrix scaledIdent = new_matrix(size,size); 
    // matrix temp = new_matrix(size,size);
    // double mag_v = vector_magnitude(v);
    // double mag_w = 1;
    // for(int i = 1; i<=size; i++)
    //     { 
    //         vget(v_new,i) = vgetp(v,i)/mag_v; 
    //     }
    // //**Evaluate lambda
    // vector Ax = matrix_vector_mult(A, &v_new);
    // lambda = vector_dot_mult(&v_new, &Ax);
    // //**Iterate
    // int k = 0;
    // int mstop = 0;
    // while (k<MaxIters && mstop==0)
    // {
    //     k++;
    //     scaledIdent = matrix_scalar_mult(&Iden, lambda);
    //     temp = matrix_sub(A, &scaledIdent);
    //     w = solve(&temp, &v_new);
    //     mag_w = vector_magnitude(&w);
    //     //**Seting v to w with magnitude 1
    //     for(int i = 1; i<=size; i++)
    //     {
    //         vget(v_new,i) = vget(w,i)/mag_w;
    //     }
    //     //**Evaluate lambda
    //     Ax = matrix_vector_mult(A, &v_new);
    //     lambda_old = lambda;
    //     lambda = vector_dot_mult(&v_new, &Ax);
    //     //**Check for convergence
    //     if (fabs(lambda-lambda_old)<Total)
    //     {
    //     mstop = 1;
    //     printf("\n Eigenvalue in %d iterations\n", k);
    //     }

    // }
    // return lambda;


    const int size = v->size;
    assert(size>0);
    assert(size==A->rows); assert(size==A->cols);

    double lambda = 1.0e0;
    double lambda_old = 0.0e0;

    vector v_new = new_vector(size);
    vector w = new_vector(size);

    // Creating identity matrix
    matrix Iden = IdentityMatrix(size);
    
    matrix scaledIdent = new_matrix(size,size); 

    // Create matrix temp
    matrix temp = new_matrix(size,size);

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
        scaledIdent = matrix_scalar_mult(&Iden, lambda);
        temp = matrix_sub(A, &scaledIdent);
        w = solve(&temp, &v_new);
        mag_w = vector_magnitude(&w);

        // Set v to w with magnitude 1
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


vector Shifted_Inversion_power_iteration(vector* v, double Mu, double Total, int MaxIters, matrix* A)
{
    const int size = v->size;
    assert(size>0);
    assert(size==A->rows); assert(size==A->cols);

    vector v_new = new_vector(size);
    vector w = new_vector(size);

    double mag_v = vector_magnitude(v);
    double mag_w = 1;

    // Set v_new to v with magnitude 1
    for(int i = 1; i<=size; i++)
        { vget(v_new,i) = vgetp(v,i)/mag_v; }

    // Iterate
    int k = 0;

    while (k<MaxIters )
    {
        k++;
        matrix Id = IdentityMatrix(size);    //create Identity matrix |A-Mu*I|
        matrix temp1 = matrix_scalar_mult(&Id, Mu);  
        matrix temp2 = matrix_sub(A, &temp1);

        w = solve(&temp2, &v_new);
        mag_w = vector_magnitude(&w);

        // Set v to w with magnitude 1
        for(int i = 1; i<=size; i++)
        { vget(v_new,i) = vget(w,i)/mag_w; }

    }
    return v_new;
}


