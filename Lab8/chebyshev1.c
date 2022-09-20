//
//  chebyshev1.c
//  
//
//  Created by Shen, Zhengyi on 9/20/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void WritePoly(const int NumPts, const double x[], double y[]);
void SamplePoly(const int N, const int NumPts, const double b[], const double x[], double y[]);

int main() {
    int N = -1;
    
    //get degree input
    while (N < 0 || N > 5) {
        printf("input N (0-5): ");
        scanf("%d", &N);
    }
    
    double b[N + 1];
    
    //get coefficients
    for (int i = 0; i < N + 1; i++) {
        printf("input b[%d]: ", i);
        scanf("%lf", &b[i]);
    }
    
    const int NumPts = 21;
    double x[NumPts];
    double y[NumPts];
    
    //set x points
    for (int i = 0; i < NumPts; i++) {
        x[i] = -1.0 + i * (2.0 / ( 1.0 * (NumPts - 1)));
    }
    
    //run calculation for y at each x point
    SamplePoly(N, NumPts, b, x, y);
    
    //write coordinets to file
    WritePoly(NumPts, x, y);
    
    //run python command
    system("python3 PlotPoly.py");
    
    return 0;
}


void WritePoly(const int NumPts, const double x[], double y[]) {
    //open file
    FILE *outfile = fopen("poly.data", "w");
    
    //write all the data points
    for (int i = 0; i < NumPts; i++) {
        fprintf(outfile, "%f %f\n", x[i], y[i]);
    }
    
    fclose(outfile);
}

void SamplePoly(const int N, const int NumPts, const double b[], const double x[], double y[]) {
    
    //loop and calculate y values
    for (int i = 0; i < NumPts; i++) {
        const double a = x[i];
        double phi = 0;
        y[i] = 0;
        
        //loop through the degree and add on all sections
        for(int k = 0; k < N + 1; k++) {
            if (k == 0) {
                phi = 1;
            }
            else if (k == 1) {
                phi = a;
            }
            else if (k == 2) {
                phi = 2 * pow(a, 2) - 1;
            }
            else if (k == 3) {
                phi = 4 * pow(a, 3) - 3 * a;
            }
            else if (k == 4) {
                phi = 8 * pow(a, 4) - 8 * pow(a, 2) + 1;
            }
            else if (k == 5) {
                phi = 16 * pow(a, 5) - 20 * pow(a, 3) + 5 * a;
            }
            y[i] += phi * b[k];
        }
    }
}
