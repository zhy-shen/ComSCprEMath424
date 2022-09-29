//
//  Peek.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//returns the value of the top node in the stack
//top: the pointer of the top of the stack
int Peek(node* top) {
    return top->value;
}
