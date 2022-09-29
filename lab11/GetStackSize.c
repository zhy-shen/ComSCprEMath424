//
//  GetStackSize.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//gets the size of the stack recursively
//top: pointer to the top of the stack
//stack size: pointer for recursively adding all nodes in a stack
void GetStackSize(node* top, int* stack_size) {
    if (top==NULL) {
        *stack_size = 0;
        return;
    }

    if (top->next == NULL) {
        *stack_size = top->position;
        return;
    }
    
    GetStackSize(top->next,stack_size);
}
