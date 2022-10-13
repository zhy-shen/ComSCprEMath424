//
//  main_matrix.c
//  
//
//  Created by Shen, Zhengyi on 10/13/22.
//

#include "matrix.h"
#include <time.h>

int main9() {
    // Get dimensions
    int N;
    printf(" Input N: ");
    scanf("%i",&N);
    assert(N>0);

    // Create matrix
    matrix create_random_matrix(const int, const int);
    matrix A = create_random_matrix(N,N);

    // Clock times
    clock_t time0,time1,time2;

    // Matrix multiply
    time0 = clock();
    matrix_mult(&A,&A);
    time1 = clock();
    matrix_mult_v2(&A,&A);
    time2 = clock();
    double cpu_time1 = ((double)(time1-time0)) / ((double)(CLOCKS_PER_SEC));
    double cpu_time2 = ((double)(time2-time1)) / ((double)(CLOCKS_PER_SEC));
    printf(" cpu_time1 = %11.5e\n",cpu_time1);
    printf(" cpu_time2 = %11.5e\n",cpu_time2);

    delete_matrix(&A);
}

matrix create_random_matrix(const int NumRows, const int NumCols) {
    srand((unsigned)time(NULL));
    matrix A = new_matrix(NumRows,NumCols);
    for (int i=1; i<=A.rows; i++)
        for (int j=1; j<=A.cols; j++)
        { mget(A,i,j) = ((double)rand()/(double)RAND_MAX); }

    return A;
}
