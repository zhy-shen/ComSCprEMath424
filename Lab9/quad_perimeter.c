//
//  quad_perimeter.c
//  
//
//  Created by Shen, Zhengyi on 9/22/22.
//

#include "main.h"
#include "quad_perimeter.h"

//q: quadrilateral to do the calculations with
void compute_perimeter(quad* q) {
    //for each of the four lines, it calculates the length of the line, and adds it to the perimeter
    //variable in the quadrilateral variable
    for (int i = 0; i < 4; i++) {
        q->perimeter += sqrt(pow(q->node[(i+1) % 4].x - q->node[i].x, 2) + pow(q->node[(i+1) % 4].y - q->node[i].y, 2));
    }
}
