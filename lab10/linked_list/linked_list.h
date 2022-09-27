//
//  linked_list.h
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

typedef struct point point;

//a point with a x and y coordinate
struct node {
    double *next;
    double *prev;
    double x;
    double y;
};

#endif /* linked_list_h */
