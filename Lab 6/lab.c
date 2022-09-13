//
//  lab.c
//  
//
//  Created by Shen, Zhengyi on 9/13/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double E_CONST = 2.7182818284590451;
int factorial_rec(int x);
double exponential(double x);
double ln(double x);

//function to calculate different values.
int main() {
    int choice = 0;
    const char *a[3];
    int x = 0;
    double n = 0;
    
    a[0] = "factorial";
    a[1] = "exponential";
    a[2] = "natural log";
    
    printf("Welcome to basic calculator, select an option to calculate\n0: run default, 1: factorial, 2: exponential, 3: natural log\n");
    
    scanf("%d", &choice);
    
    //run default values to test all 3 functions
    if (choice == 0) {
        printf("Running default values...\n\n");
        
        int n = 5;
        double x = 3.0;
        double y = 11.0;
        printf("EXP of %f\n", x);
        printf("%f\n", exponential(x));
        printf("factorial of %d\n", n);
        printf("%d\n", factorial_rec(n));
        printf("ln of %f\n", y);
        printf("%f\n", ln(y));
    }
    else {
        printf("You chose: %s, what is the input?\n", a[choice - 1]);
        
        //use integers if factorial is chosen
        if (choice == 1) {
            scanf("%d", &x);
            int result = 0;
            
            result = factorial_rec(x);
            
            //print results
            printf("The %s of %d is: %d\n", a[choice - 1], x, result);
        }
        
        //use doubles if either exponential or natural log is chosen
        if (choice == 2 || choice == 3) {
            scanf("%lf", &n);
            double result = 0;
            
            if (choice == 2) {
                result = exponential(n);
            }
            else {
                result = ln(n);
            }
            
            //print results
            printf("The %s of %f is: %f\n", a[choice - 1], n, result);
        }
    }
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
        s = x * factorial_rec(x-1);
    }
    return s;
}

//function to solve exponential, functionality similar to python version
double exponential(double x) {
    double tol = pow(10,-14);
    int kmax = 100;
    int x0 = round(x);
    
    int z = x - x0;
    double tempNum = 0;
    double currentNum = 0;
    
    for (int i = 0; i < kmax; i++) {
        currentNum = tempNum * pow(E_CONST, x0);
        tempNum += pow(z,i) / factorial_rec(i);
        
        if (fabs(tempNum * pow(E_CONST, x0) - currentNum) < tol) {
            return tempNum * pow(E_CONST, x0);
        }
    }
    
    return tempNum * pow(E_CONST, x0);
}

//function to solve natural log, functionality similar to python version
double ln(double x){
    double tol = pow(10,-14);
    int kmax = 100;
    double s = x * 1.0;
    double currentNum = 0;
    
    for (int i = 0; i < kmax; i++) {
        currentNum = s;
        s = s - 1.0 + pow(E_CONST, -1.0 * s) * x * 1.0;
        if (fabs(s - currentNum) < tol) {
            return s;
        }
    }
    
    return s;
}
