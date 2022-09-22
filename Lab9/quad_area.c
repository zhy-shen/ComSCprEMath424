//
//  quad_area.c
//  
//
//  Created by Shen, Zhengyi on 9/22/22.
//

#include "main.h"
#include "quad_area.h"

//split the quadrilateral into two triangles and do the calculations on each half separately
void compute_area(quad* q) {
    double u1[3], v1[3], w1[3], u2[3], v2[3], w2[3];
    
    //first triangle
    u1[0] = q->node[2].x - q->node[1].x;
    u1[1] = q->node[2].y - q->node[1].y;
    u1[2] = 0.0;
    
    v1[0] = q->node[0].x - q->node[1].x;
    v1[1] = q->node[0].y - q->node[1].y;
    v1[2] = 0.0;
    
    //calculate the area of the first triangle
    cross_prod(u1, v1, w1);
    
    //second triangle
    u2[0] = q->node[2].x - q->node[3].x;
    u2[1] = q->node[2].y - q->node[3].y;
    u2[2] = 0.0;
    
    v2[0] = q->node[0].x - q->node[3].x;
    v2[1] = q->node[0].y - q->node[3].y;
    v2[2] = 0.0;
    
    //calculate the area of the second triangle
    cross_prod(u2, v2, w2);
    
    //add the two triangles together to get the total area of the quadrilateral
    q->area = 0.5 * fabs(w1[2]) + 0.5 * fabs(w2[2]);
}

//cross product function to get the area of each triangle * 2
void cross_prod (double u[], double v[], double w[]) {
    w[0] = u[1] * v[2] - u[2] * v[1];
    w[1] = u[2] * v[0] - u[0] * v[2];
    w[2] = u[0] * v[1] - u[1] * v[0];
}
