//
//  main_throughput.c
//  
//
//  Created by Shen, Zhengyi on 10/13/22.
//

#include "matrix.h"
#include <time.h>
//CLOCKS_PER_SEC


int main3() {
    // Get dimensions
    int N=0;
    printf(" Input N: "); scanf("%i",&N);
    assert(N>0);

    matrix A = new_matrix(N,N);
    matrix B = new_matrix(N,N);

    clock_t time0 = clock();
    matrix C = matrix_add(&A,&B);
    clock_t time1 = clock();
    matrix D = matrix_mult_v2(&A,&B);
    clock_t time2 = clock();
    // Report times
    double cpu_time1 = ((double)(time1-time0)) / ((double)(CLOCKS_PER_SEC));
    double cpu_time2 = ((double)(time2-time1)) / ((double)(CLOCKS_PER_SEC));
    double ND = (double)(N);
    double nflops1 = ND*ND;
    double nflops2 = (2.0*ND-1.0)*ND*ND;
    double mega1 = 1.0e-6*nflops1/(cpu_time1);
    double mega2 = 1.0e-6*nflops2/(cpu_time2);

    printf("\n Add:\n");
    printf(" CPU time: %11.5e (sec)\n",cpu_time1);
    printf(" rate: %11.5e (megaflop/sec)\n",mega1);

    printf("\n Multiply:\n");
    printf(" CPU time: %11.5e (sec)\n",cpu_time2);
    printf(" rate: %11.5e (megaflop/sec)\n",mega2);

    delete_matrix(&A); delete_matrix(&B);
    delete_matrix(&C); delete_matrix(&D);
}
