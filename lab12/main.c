//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 10/4/22.
//

#include "matrix.h"

//runs all functions in this program
int main() {
    // Matrices
    matrix A = new_matrix(3,3);
    matrix B = new_matrix(3,3);
    
    //uses the matrix example from the python lab
    mget(A,1,1) = -2.0;
    mget(A,1,2) = 0.0;
    mget(A,1,3) = 1.0;
    mget(A,2,1) = -1.0;
    mget(A,2,2) = 7.0;
    mget(A,2,3) = 1.0;
    mget(A,3,1) = 5.0;
    mget(A,3,2) = -1.0;
    mget(A,3,3) = 1.0;

    for(int i=1; i<=3; i++ ){
        for (int j=1; j<=3; j++ ) {
            mget(B,i,j) = 2.0*(i==j) + 1.0*(i-1==j) + 1.0*(j-1==i);
        }
    }
    
    // Print matrices
    print_matrix(&A);
    print_matrix(&B);
        
    // Add/Subtract/Multiply matrices
    matrix Csum = matrix_add(&A,&B);
    print_matrix(&Csum);
    
    matrix Cdiff = matrix_sub(&A,&B);
    print_matrix(&Cdiff);
    
    matrix Cprod = matrix_mult(&A,&B);
    print_matrix(&Cprod);
    
    matrix Cdot = matrix_dot_mult(&A,&B);
    print_matrix(&Cdot);

    // Vectors
    vector x = new_vector(3);
    vector y = new_vector(3);

    vget(y,1) = -4.0; vget(x,1) = 1.0;
    vget(y,2) = -50.0; vget(x,2) = 2.0;
    vget(y,3) = -26.0; vget(x,3) = 3.0;

    // Print vectors
    print_vector(&x);
    print_vector(&y);
    
    // Add/Subtract/Multiply vectors
    vector zsum = vector_add(&x,&y);
    print_vector(&zsum);
    
    vector zdiff = vector_sub(&x,&y);
    print_vector(&zdiff);
    
    double zdot = vector_dot_mult(&x,&y);
    print_scalar(&zdot);

    // Matrix vector multiply
    vector Ax = matrix_vector_mult(&A,&x);
    print_vector(&Ax);

    // Linear solve via Gaussian elimination
    vector soln = solve(&A,&y);
    print_vector(&soln);
}
