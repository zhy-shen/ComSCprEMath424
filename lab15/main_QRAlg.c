//
//  main_QRAlg.c
//  
//
//  Created by Shen, Zhengyi on 10/13/22.
//

#include "matrix.h"
#include "trimatrix.h"
#include <time.h>

int main() {
    srand( time(NULL) );
    int N=50;

    // Create a random symmetric matrix
    matrix A = new_matrix(N,N);

    for (int i=1; i<=N; i++)
        for (int j=1; j<=i; j++)
        {
            double tmp = ((double)rand())/((double)RAND_MAX);
            tmp = (double)((int)(10000.0*tmp))/10000.0;
            mget(A,i,j) = tmp;
        }
    
    for (int i=1; i<=(N-1); i++)
        for (int j=(i+1); j<=N; j++)
        { mget(A,i,j) = mget(A,j,i); }

    void QRA(trimatrix* T);
    void Hessenberg(const matrix* A, trimatrix* T);
    trimatrix T = new_trimatrix(N);
    Hessenberg(&A,&T);
    QRA(&T);
    printf("\n Eigenvalues of A:\n");
    
    for (int i=1; i<=N; i++)
    { printf(" lambda(%3i) = %24.16e\n",i,tget(&T,i,i)); }
    printf("\n");
}
