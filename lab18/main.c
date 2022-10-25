//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 10/18/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif
void openMP(const int N, const int k, vector *v);

//make n and k enter-able
int main(int argc , char* argv []) {
    void usage(const char* prog_name );
    
    if (argc != 3) { usage(argv [0]); }
    const int thread_count = strtol(argv [1], NULL , 10);
    const int N = strtol(argv [2], NULL , 10);
    
    if ( thread_count <= 0) {
        usage(argv [0]);
    }
    
    srand( time(NULL) );
    const double time1 = omp_get_wtime ();
    
    vector v = new_vector(N);
    
    for (int i = 1; i <= N; i++) {
        vget(v,i) = 1;
    }
    
    double norm = 0;
    
# pragma omp parallel num_threads(thread_count)
{
    const int my_rank = omp_get_thread_num();

    const int N_per_thread = N / thread_count;
    const int istart = my_rank * N_per_thread + 1;
    const int iend = (my_rank + 1) * (N_per_thread);

    double norm_thread = 0.0;
    for (int i = istart; i <= iend; i++)
    { norm_thread += pow(fabs(vget(v,i)), 2); }
    
# pragma omp critical
    norm += norm_thread;

# pragma omp barrier
    
# pragma omp single
    norm = sqrt(norm);
    
    for (int i = istart; i <= iend; i++)
    { vget(v,i) = vget(v,i) / norm; }
}
    
    const double time2 = omp_get_wtime ();
    const double clock_time = time2 -time1;
    
    printf(" Norm: %12.5e, with %i threads , clock_time = %11.5e (sec)\n", norm, thread_count , clock_time );
    //print_vector(&v);
    
    return 0;
}


void usage(const char * prog_name ) {
    fprintf(stderr , "usage: %s <thread_count > <matrix size > <k>\n", prog_name );
    fprintf(stderr , " thread_count should be positive\n");
    fprintf(stderr , " N should be positive\n");
    exit (1);
}
