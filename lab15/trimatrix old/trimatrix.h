//
//  trimatrix.h
//
//
//  Created by Shen, Zhengyi on 10/11/22.
//

#ifndef trimatrix_h
#define trimatrix_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "matrix.h"

typedef struct trimatrix trimatrix;
struct trimatrix {
    int rows;
    int cols;
    double* left;
    double* center;
    double* right;
};
typedef struct pentamatrix pentamatrix;
struct pentamatrix {
    int rows;
    int cols;
    double* leftleft;
    double* left;
    double* center;
    double* right;
    double* rightright;
};

#define print_trimatrix(mat) print_trimatrix_full(mat,#mat);

trimatrix new_trimatrix(const int rows);
double tget(const trimatrix * trimat, const int i, const int j);
void tset(trimatrix * trimat, const int i, const int j, const double val);
void print_trimatrix_full(const trimatrix* mat, char* varname);
trimatrix grab_sub_trimatrix(trimatrix * T, int k1, int k2);
trimatrix merge_sub_trimatrix(trimatrix * T1, trimatrix * T2);
void Hessenberg(const matrix * Ain, trimatrix * T);
void QRA(trimatrix *T);

#endif /* trimatrix_h */
