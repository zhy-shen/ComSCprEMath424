//
//  matrix.h
//  
//
//  Created by Shen, Zhengyi on 10/4/22.
//

#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct matrix matrix;
struct matrix {
    int rows;
    int cols;
    double* val;
};

typedef struct vector vector;
struct vector {
    int size;
    double* val;
};

// Shortcut evaluate functions
#define mget(mat,i,j) mat.val[(i-1)*mat.cols+(j-1)]
#define mgetp(mat,i,j) mat->val[(i-1)*mat->cols+(j-1)]
#define vget(vec,i) vec.val[(i-1)]
#define vgetp(vec,i) vec->val[(i-1)]
#define print_matrix(mat) print_matrix_full(mat,#mat);
#define print_vector(vec) print_vector_full(vec,#vec);
#define print_scalar(z) print_scalar_full(z,#z);

// Function declarations
matrix new_matrix(const int rows, const int cols);
void print_matrix_full(const matrix* mat, char* varname);
matrix matrix_add(const matrix* A, const matrix* B);
matrix matrix_sub(const matrix* A, const matrix* B);
matrix matrix_mult(const matrix* A, const matrix* B);
matrix matrix_dot_mult(const matrix* A, const matrix* B);
//
vector new_vector(const int size);
void print_vector_full(const vector* vec, char* varname);
vector vector_add(const vector* x, const vector* y);
vector vector_sub(const vector* x, const vector* y);
double vector_dot_mult(const vector* x, const vector* y);
//
void print_scalar_full(const double* z, char* varname);
//
vector matrix_vector_mult(const matrix* A, const vector* x);
//
vector solve(const matrix* A, const vector* b);

double magnitude(vector* x);
vector normalize(vector* x);
double power_iter (vector* v0, double tol, int max_iters, matrix* A);
double si_power_iter (double mu, vector* v0, double tol, int max_iters, matrix* A);
double rayleigh_iter (vector* v0, double tol, int max_iters, matrix* A);

#endif /* matrix_h */
