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
    mget(A,2,2) = 8.0;
    mget(A,3,3) = 5.0;
    
    // Print vectors
    
    print_matrix(&A);
    print_vector(&x);


    printf("Power Iter Result: %lf\n\n", power_iter(&x, 0.0000001, 100, &A));
    printf("Rayleigh Result: %lf\n\n", rayleigh_iter(&x, 0.0000001, 100, &A));
    printf("Shifted Inverse Result (Guess 1.0): %lf\n\n", si_power_iter(1.0, &x, 0.0000001, 100, &A));
}
