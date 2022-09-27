//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 9/22/22.
//

#include "main.h"

int main() {
    //initialize quadrilateral
    quad q;
    q.node[0].x = 2.0; q.node[0].y = 4.0;
    q.node[1].x = 0.0; q.node[1].y = 0.0;
    q.node[2].x = 5.0; q.node[2].y = 0.0;
    q.node[3].x = 5.0; q.node[3].y = 4.0;
    
    //for each of the points print out the coordinates
    for (int i = 0; i < 4; i++) {
        printf("quad point %d = x: %2.1f, y: %2.1f\n", i, q.node[i].x, q.node[i].y);
    }
    
    //run the function to compute the area
    compute_area(&q);
    
    //run the function to compute the perimeter
    compute_perimeter(&q);
    
    //run function to compute angle
    compute_inner_angle(&q);
    
    printf("quad area: %lf\n", q.area);
    printf("quad peri: %lf\n", q.perimeter);
    printf("quad inner_angle: %lf * pi radians\n", q.inner_angle / CONST_PI);
}
