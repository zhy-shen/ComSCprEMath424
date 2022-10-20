//
//  forloop.c
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
    
    if (argc != 4) { usage(argv [0]); }
    const int thread_count = strtol(argv [1], NULL , 10);
    const int N = strtol(argv [2], NULL , 10);
    const int kCount = strtol(argv [3], NULL , 200);
    
    if ( thread_count <= 0) {
        usage(argv [0]);
    }
    
    srand( time(NULL) );
    const double time1 = omp_get_wtime ();
    
    vector v = new_vector(N);
    
#   pragma omp parallel num_threads(thread_count)
    openMP(N,kCount,&v);
    
    const double time2 = omp_get_wtime ();
    const double clock_time = time2 -time1;
    
    printf(" With %i threads , clock_time = %11.5e (sec)\n", thread_count , clock_time );
    print_vector(&v);
    
    return 0;
}

void openMP(const int N, const int k, vector *v) {
#   ifdef _OPENMP
    const int my_rank = omp_get_thread_num();
    const int actual_thread_count = omp_get_num_threads();
#   else
    const int my_rank = 0;
    const int actual_thread_count = 1;
#   endif
    
    int chunk = N / ( actual_thread_count );
    
    for(int i = (my_rank * chunk); i <= (my_rank + 1) * chunk; i++ ) {
        double row = 0;
        for(int j = 1; j <= k; j++) {
            double aij = 1.0 / (i + j - 1);
            row += aij;
        }
        vgetp(v, i) = row;
    }
}

void usage(const char * prog_name ) {
    fprintf(stderr , "usage: %s <thread_count > <matrix size > <k>\n", prog_name );
    fprintf(stderr , " thread_count should be positive\n");
    fprintf(stderr , " N should be positive\n");
    exit (1);
}
