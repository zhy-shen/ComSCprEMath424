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
    
    vector x = new_vector(3);

    vget(x,1) = 1.0;
    vget(x,2) = 2.0;
    vget(x,3) = 3.0;

    mget(A,1,1) = 4.0;
    mget(A,1,2) = 0.0;
    mget(A,1,3) = 0.0;
    mget(A,2,1) = 0.0;
    mget(A,2,2) = 8.0;
    mget(A,2,3) = 0.0;
    mget(A,3,1) = 0.0;
    mget(A,3,2) = 0.0;
    mget(A,3,3) = 5.0;
    
    // Print vectors
    
    print_matrix(&A);
    print_vector(&x);
    
    printf("%lf\n", power_iter(&x, 0.0000001, 100, &A));
}
