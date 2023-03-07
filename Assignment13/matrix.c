#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"
#include <time.h>

// **! Creating a new matrix
matrix new_matrix (const int rows , const int cols)
{
    matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    assert(rows >0);
    assert(cols >0);
    mat.val = (double*) malloc(sizeof(double)*rows*cols);

    for (int i=0; i<( rows*cols); i++)
    { 
        mat.val[i] = 0.0; 
    }

 return mat;

}

    //**! printing a matrix

void print_matrix_full (const matrix* mat , char* varname)
{
    assert(mat ->rows >0); assert(mat ->cols >0);
    printf("\n %.100s =\n", &varname [1] );
    for(int i=1; i<=mat ->rows; i++ )
    {
        printf(" | ");
        for(int j=1; j<=mat ->cols; j++)
        {
            printf("%0.5f",mgetp(mat ,i,j));
            if (j<mat ->cols) {printf(", ");}
            else {printf(" ");}
        }
        printf("|\n");
    }
    printf("\n");

}


//**! MAtrix Multiplication

matrix matrix_mult (const matrix* A, const matrix* B)
{
    const int rowsA = A->rows; 
    const int colsA = A->cols;
    const int rowsB = B->rows; 
    const int colsB = B->cols;
    assert(colsA == rowsB);
    matrix C = new_matrix(rowsA, colsB);

    for (int i = 1; i <= rowsA; i++)
        for (int j = 1; j <= colsB; j++)
            for (int k = 1; k <= colsA; k++)
            {
                mget(C, i, j) += mgetp(A, i, k) * mgetp(B, k, j);
            }

    return C;
}


//**! transpose matrix
matrix matrix_transpose(const matrix *A){
   int row = A->rows;
   int col = A->cols;

    matrix b = new_matrix(row,col);

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            mget(b, j, i) = mgetp(A, i, j);
        }
    }
    return b;
}


//**! New vector
vector new_vector (const int size)
{
    srand(time(NULL));
    vector vec;
    vec.size = size;
    assert(size >0);
     vec.val = (double*) malloc(sizeof(double)*size);
    
    for (int i=0; i<( size); i++)
    {
        vec.val[i] = (double)rand() / RAND_MAX; 
    }

    return vec;
}

//**! printing vector 
void print_vector_full(const vector* vec, char* varname) {
    assert(vec->size > 0);
    printf("\n");
    printf(" %.100s =\n", &varname[1]);
    printf(" | ");
    for (int i = 1; i <= vec->size; i++) {
        printf("%0.5f", vgetp(vec, i));
        if (i < vec->size) {
            printf(", ");
        }
    }
    printf(" |^T\n\n");
}


//**! Gaussion method
vector solve(const matrix* A, const vector* b)
{
    const int rows = A->rows; const int cols = A->cols;
    const int size = b->size;
    assert(rows == cols); assert(rows == size);

    vector x = new_vector(rows);
    

    for (int i=1; i <=( size -1); i++) // LOOP OVER EACH COLUMN
    {
    // Select largest pivot in current column
    int p=i; double maxA = -100.0e0;
    for (int j=i; j<= size; j++)
    {
        double tmp = fabs(mgetp(A,j,i));
        if ( tmp > maxA ){ p = j; maxA = tmp; }
    }

    // See if matrix is singular
    if (maxA <= 1.0e-14)
    { 
        printf(" Cannot invert system\n"); exit (1); 
    }

    // Pivot (aka interchange rows)
    if (p!=i)
    {
        for (int j=1; j<= size; j++)
        {
            double tmp1 = mgetp(A,i,j);
            mgetp(A,i,j) = mgetp(A,p,j); mgetp(A,p,j) = tmp1;
            }
        
        double tmp2 = vgetp(b,i);
        vgetp(b,i) = vgetp(b,p); vgetp(b,p) = tmp2;
    }

    //**! Eliminate below diagonal
    for (int j=(i+1); j<= size; j++)
    {
        double dm = mgetp(A,j,i)/mgetp(A,i,i);

        for (int k=1; k<= size; k++)
        { 
            mgetp(A,j,k) = mgetp(A,j,k) - dm*mgetp(A,i,k); 
        }

        vgetp(b,j) = vgetp(b,j) - dm*vgetp(b,i);
    }
    }

return x;
}



