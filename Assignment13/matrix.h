#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct matrix matrix;
struct matrix
    { 
    int rows; int cols; double* val; 
    };


typedef struct vector vector;
struct vector
    { 
        int size; double* val; 
    };


#define mget(mat,i,j) mat.val[(i-1)*mat.cols+(j-1)]
#define mgetp(mat,i,j) mat->val[(i-1)*mat->cols+(j-1)]
#define vget(vec,i) vec.val[(i-1)]
#define vgetp(vec,i) vec->val[(i-1)]
#define print_matrix(mat) print_matrix_full(mat ,#mat);
#define print_vector(vec) print_vector_full(vec ,#vec);

matrix new_matrix(const int rows , const int cols);
vector new_vector (const int size);
vector solve(const matrix* A, const vector* b);
void print_matrix_full (const matrix* mat , char* varname);
void print_vector_full (const vector* vec , char* varname);
matrix matrix_mult (const matrix* A, const matrix* B);
matrix matrix_transpose(const matrix *A);

#endif