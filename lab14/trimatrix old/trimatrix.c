//
//  trimatrix.c
//
//
//  Created by Shen, Zhengyi on 10/11/22.
//

#include "trimatrix.h"


/**
 *this function prints the given matrix
 *input:
 *  mat: input matrix to print
 *  varname: label to print out with the matrix
 *output: n/a
 */
void print_trimatrix_full(const trimatrix* mat, char* varname) {
    assert(mat->rows>0); assert(mat->cols>0);
    printf("\n %.100s =\n", &varname[1] );
    
    for(int i=1; i<=mat->rows; i++ ) {
        printf(" | ");
        
        for(int j=1; j<=mat->cols; j++) {
            printf("%10.3e",mgetp(mat,i,j));
            if (j<mat->cols) {
                printf(", ");
            }
            else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

trimatrix new_trimatrix(const int rows) {
    trimatrix trimat;
    assert(rows > 0);
    trimat.rows = rows;
    trimat.cols = rows;
    trimat.left = (double*) malloc(sizeof(double) * rows);
    trimat.center = (double*) malloc(sizeof(double) * rows);
    trimat.right = (double*) malloc(sizeof(double) * rows);

    for (int i = 0; i < (rows); i++) {
        trimat.left[i] = 0.0;
        trimat.center[i] = 0.0;
        trimat.right[i] = 0.0;
    }

    return trimat;
}

double tget(const trimatrix * trimat, const int i, const int j) {
    if (i == j) {
        return trimat -> center[i - 1];
    } else if (i == (j + 1)) {
        return trimat -> left[i - 1];
    } else if (i == (j - 1)) {
        return trimat -> right[i - 1];
    } else {
        return 0.0;
    }
}

void tset(trimatrix * trimat, const int i, const int j, const double val) {
    if (i == j) {
        trimat -> center[i - 1] = val;
    } else if (i == (j + 1)) {
        trimat -> left[i - 1] = val;
    } else if (i == (j - 1)) {
        trimat -> right[i - 1] = val;
    }
}

trimatrix grab_sub_trimatrix(trimatrix * T, int k1, int k2) {
    const int size = k2 - k1 + 1;
    assert(T -> rows > 0);
    assert(k1 > 0);
    assert(k2 >= k1);
    assert(k2 <= T -> rows);

    trimatrix Tnew = new_trimatrix(size);
    const int shift = k1 - 1;

    tset(&Tnew, 1, 1, tget(T, 1 + shift, 1 + shift));
    tset(&Tnew, 1, 2, tget(T, 1 + shift, 2 + shift));
    for (int i = 2; i <= (size - 1); i++) {
        tset(&Tnew, i, i - 1, tget(T, i + shift, i + shift - 1));
        tset(&Tnew, i, i, tget(T, i + shift, i + shift));
        tset(&Tnew, i, i + 1, tget(T, i + shift, i + shift + 1));
    }
    tset(&Tnew, size, size - 1, tget(T, size + shift, size + shift - 1));
    tset(&Tnew, size, size, tget(T, size + shift, size + shift));

    return Tnew;
}

trimatrix merge_sub_trimatrix(trimatrix * T1, trimatrix * T2) {
    const int k1 = T1 -> rows;
    assert(k1 > 0);
    const int k2 = T2 -> rows;
    assert(k2 > 0);
    const int N = k1 + k2;

    trimatrix T = new_trimatrix(N);

    tset(&T, 1, 1, tget(T1, 1, 1));
    tset(&T, 1, 2, tget(T1, 1, 2));
    for (int i = 2; i <= (k1 - 1); i++) {
        tset(&T, i, i - 1, tget(T1, i, i - 1));
        tset(&T, i, i, tget(T1, i, i));
        tset(&T, i, i + 1, tget(T1, i, i + 1));
    }
    tset(&T, k1, k1 - 1, tget(T1, k1, k1 - 1));
    tset(&T, k1, k1, tget(T1, k1, k1));

    tset(&T, k1 + 1, k1 + 1, tget(T2, 1, 1));
    tset(&T, k1 + 1, k1 + 2, tget(T2, 1, 2));
    for (int i = 2; i <= (k2 - 1); i++) {
        tset(&T, k1 + i, k1 + i - 1, tget(T2, i, i - 1));
        tset(&T, k1 + i, k1 + i, tget(T2, i, i));
        tset(&T, k1 + i, k1 + i + 1, tget(T2, i, i + 1));
    }
    tset(&T, k1 + k2, k1 + k2 - 1, tget(T2, k2, k2 - 1));
    tset(&T, k1 + k2, k1 + k2, tget(T2, k2, k2));

    return T;
}

