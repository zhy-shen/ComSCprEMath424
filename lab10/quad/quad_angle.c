//
//  quadrilateral_angle.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include "main.h"

//q: quadrilateral to do the calculations with
void compute_inner_angle(quad* q) {
    //for each of the four lines, it calculates the length of the line, and adds it to the perimeter
    //variable in the quadrilateral variable
    
    double length[4];
    double u[4][3];
    
    for (int i = 0; i < 4; i++) {
        length[i] = sqrt(pow(q->node[(i+1) % 4].x - q->node[i].x, 2) + pow(q->node[(i+1) % 4].y - q->node[i].y, 2));
        
        u[i][0] = q->node[(i+1) % 4].x - q->node[i].x;
        u[i][1] = q->node[(i+1) % 4].y - q->node[i].y;
        u[i][2] = 0.0;
    }
    
    for (int i = 0; i < 4; i++) {
        q->inner_angle += acos(compute_dot_product(u[i], u[(i+1) % 4]) / length[i] / length[(i+1) % 4]);
        printf("Angle: %lf\n", acos(compute_dot_product(u[i], u[(i+1) % 4]) / length[i] / length[(i+1) % 4]));
    }
}

double compute_dot_product(double u[], double v[]) {
    double temp = 0;
    for (int i = 0; i < 3; i++){
        temp += u[i] * v[i];
    }
    return temp;
}
