//
//  eigensolve.c
//  
//
//  Created by Shen, Zhengyi on 10/6/22.
//

#include "matrix.h"

//helper function for calculating the magnitude of a vector
double magnitude(vector* x) {
    return sqrt(vector_dot_mult(x, x));
}

//normalizes a vector
vector normalize(vector* x) {
    const int size = x->size;
    vector z = new_vector(size);
    double mag = sqrt(vector_dot_mult(x, x));

    //divides each point by the vector magnitude
    for (int i=1; i<=size; i++) {
        vget(z,i) = vgetp(x,i) / mag;
    }

    return z;
}


/**
 * Finds the largest eigenvalue with the Power Iteration Algorithm
 *
 * @param v0: vector
 * @param tol: tolerance to end calculation
 * @param max_iters: maximum iterations of loop
 * @param A: matrix to find eigenvalue for
 * @return largest eigenvalue
 */
double power_iter (vector* v0, double tol, int max_iters, matrix* A) {
    const int size = v0->size;

    //set up variables
    vector v = new_vector(size);
    v = normalize(v0);


    //l0: lamda 0
    //lk: lamda k
    //lk1: lamda k-1

    vector Av = matrix_vector_mult(A, &v);
    double l0 = vector_dot_mult(&v, &Av);
    
    
    vector vk = new_vector(size), Av_pre = new_vector(size);
    
    int mstop = 0, k = 0;
    vector w = new_vector(size);
    w = Av;
    double lk1 = l0;
    double lk;
    
    while(!mstop) {
        k++;
        
        if (k != 1) {
            w = Av_pre;
        }
        
        vk = normalize(&w);
        Av = matrix_vector_mult(A, &vk);
        lk = vector_dot_mult(&vk, &Av);
        
        //printf("iters: %d, %lf, %lf\n", k, lk, lk1);

        //stop when the difference is less than the tolerance between loops
        if ((lk - lk1) < tol || k == max_iters){
            mstop = 1;
        }
        lk1 = lk;
        
        Av_pre = Av;
    }
    
    printf("iters: %d\n", k);
    
    return lk;
}

/**
 * Returns the closest eigenvalue to the guess using the Shifted Inverse Power Iteration Algorithm
 *
 * @param mu: guess for the eigenvalue
 * @param v0: vector
 * @param tol: tolerance to end loop
 * @param max_iters: maximum iterations of loop
 * @param A: matrix to calculate eigenvalue
 * @return eigenvalue closest to guess
 */
double si_power_iter (double mu, vector* v0, double tol, int max_iters, matrix* A) {
    const int size = v0->size;
    
    
    matrix ul = new_matrix(3,3);

    //set the matrix diagonal to be the guess
    mget(ul,1,1) = mu;
    mget(ul,2,2) = mu;
    mget(ul,3,3) = mu;


    vector v = new_vector(size);
    v = normalize(v0);


    vector Av = matrix_vector_mult(A, &v);
    double lamda0 = vector_dot_mult(&v, &Av);
    
    vector vk = new_vector(size);
    
    int mstop = 0, k = 0;
    vector w = new_vector(size);
    matrix sub = new_matrix(3,3);

    
    double lk1 = lamda0;
    //printf("lamda0: %lf\n", lamda0);
    double lk;
    vk = v;

    while(!mstop) {
        k++;

        sub = matrix_sub(A, &ul);
        w = solve(&sub, &vk);
        
        vk = normalize(&w);
        Av = matrix_vector_mult(A, &vk);
        lk = vector_dot_mult(&vk, &Av);

        //printf("iters: %d, lk: %lf, lk1: %lf\n", k, lk, lk1);

        //stop when the difference is less than the tolerance between loops
        if (fabs(lk - lk1) < tol || k == max_iters){
            mstop = 1;
        }
        lk1 = lk;
    }
    
    printf("iters: %d\n", k);
    
    return lk;
}

/**
 * Calculates eigenvalue using Rayleigh Quotient Iteration
 * @param v0: vector
 * @param tol: tolerance to end loop
 * @param max_iters: maximum iterations of loop
 * @param A: matrix to calculate eigenvalue for
 * @return eigenvalue of matrix
 */
double rayleigh_iter (vector* v0, double tol, int max_iters, matrix* A) {
    const int size = v0->size;

    matrix ul = new_matrix(3,3);

    vector v = new_vector(size);
    v = normalize(v0);


    vector Av = matrix_vector_mult(A, &v);
    double lamda0 = vector_dot_mult(&v, &Av);

    //set the matrix diagonal to be initial lamda value
    mget(ul,1,1) = lamda0;
    mget(ul,2,2) = lamda0;
    mget(ul,3,3) = lamda0;

    vector vk = new_vector(size);

    int mstop = 0, k = 0;
    vector w = new_vector(size);
    matrix sub = new_matrix(3,3);


    double lk1 = lamda0;
    //printf("lamda0: %lf\n", lamda0);

    double lk;
    vk = v;

    while(!mstop) {
        k++;

        sub = matrix_sub(A, &ul);
        w = solve(&sub, &vk);

        vk = normalize(&w);
        Av = matrix_vector_mult(A, &vk);
        lk = vector_dot_mult(&vk, &Av);

        //printf("iters: %d, lk: %lf, lk1: %lf\n", k, lk, lk1);

        //stop when the difference is less than the tolerance between loops
        if (fabs(lk - lk1) < tol || k == max_iters){
            mstop = 1;
        }

        //reset the matrix diagonal to current lamda value
        mget(ul,1,1) = lk;
        mget(ul,2,2) = lk;
        mget(ul,3,3) = lk;
        lk1 = lk;
    }

    printf("iters: %d\n", k);

    return lk;
}