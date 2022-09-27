//
//  main.h
//  
//
//  Created by Shen, Zhengyi on 9/22/22.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct quad quad;
typedef struct point point;
void compute_perimeter(quad* q);
void compute_area(quad* q);
void compute_inner_angle(quad* q);
void cross_prod (double u[], double v[], double w[]);
double compute_dot_product(double u[], double v[]);

static const double CONST_PI = 3.14159265359;

//#include "quad_perimeter.h"
//#include "quad_area.h"

//a point with a x and y coordinate
struct point {
    double x;
    double y;
};

//a quad with a point array to store the 4 points
//area: store the area of the quad
//perimeter: store the perimeter of the quad
struct quad {
    point node[4];
    double area;
    double perimeter;
    double inner_angle;
};

#endif /* main_h */
