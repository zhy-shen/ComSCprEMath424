//
//  ComputeExp.c
//  
//
//  Created by Shen, Zhengyi on 9/15/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double E_CONST = 2.7182818284590451;
int factorial_rec(int x);
double exponential(double x);

int main() {
    int n[11] = {0,1,2,3,4,5,6,7,8,9,10};
    
    printf("Running default values...\n\n");
    
    for (int i = 0; i < 11; i++) {
        printf("EXP of %d: %f\n", n[i], exponential(n[i]));
    }
    
    printf("\n");
}

//function to solve exponential, functionality similar to python version
double exponential(double x) {
    double tol = pow(10,-14);
    int kmax = 100;
    int x0 = floor(x);
    
    //solve for z
    double z = x - x0;
    double tempNum = 0;
    double currentNum = 0;
    double calc = 0;
    
    //solve for the chain of fractions added together
    for (int i = 0; i < kmax; i++) {
        tempNum += pow(z,i) / factorial_rec(i);
        calc = tempNum * pow(E_CONST, x0);

        if (fabs(tempNum * pow(E_CONST, x0) - currentNum) < tol) {
            return tempNum * pow(E_CONST, x0);
        }
        
        currentNum = tempNum * pow(E_CONST, x0);
    }
    
    return tempNum * pow(E_CONST, x0);
}

//recursive function to calculate the factorial of a integer
int factorial_rec(int x){
    int s = 0;
    
    //round input if it didn't error out already
    x = round(x);
    if (x < 0) {
        printf("input not valid (negative number)");
        return -1;
    }
    
    //return 1 is input is 0
    else if (x == 0) {
        return 1;
    }
    else {
        //recursively get the factorial of the number below it
        s = x * factorial_rec(x-1);
    }
    return s;
}
