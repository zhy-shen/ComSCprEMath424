//
//  eigensolve.c
//  
//
//  Created by Shen, Zhengyi on 10/6/22.
//

#include "matrix.h"

double magnitude(vector* x) {
    return sqrt(vector_dot_mult(x, x));
}

vector normalize(vector* x) {
    const int size = x->size;
    vector z = new_vector(size);
    double mag = sqrt(vector_dot_mult(x, x));
    
    for (int i=1; i<=size; i++) {
        vget(z,i) = vgetp(x,i) / mag;
    }

    return z;
}

double power_iter (vector* v0, double tol, int max_iters, matrix* A) {
    const int size = v0->size;
    
    vector v = new_vector(size);
    v = normalize(v0);
    
    vector Av = matrix_vector_mult(A, &v);
    double l0 = vector_dot_mult(&v, &Av);
    
    
    vector vk = new_vector(size), Avk = new_vector(size), Av_pre = new_vector(size);
    
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
        
        printf("iters: %d, %lf, %lf\n", k, lk, lk1);
        
        if ((lk - lk1) < tol || k == max_iters){
            mstop = 1;
        }
        lk1 = lk;
        
        Av_pre = Av;
    }
    
    printf("iters: %d\n", k);
    
    return lk;
}

double si_power_iter (int mu, vector* v0, double tol, int max_iters, matrix* A) {
    return 0.0;
}
