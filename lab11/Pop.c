//
//  Pop.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//removes the top node in the stack
//top: pointer to the top of the stack
//output: the value of the popped node
void Pop(node** top, int* output) {
    node* temp = *top;
    if (temp==NULL) {
        return;
    }
    else {
        temp = temp->next;
    }
    *output = (*top)->value;
    free(*top);
    *top = temp;

    node* ptr = *top;
    while (ptr!=NULL) {
        ptr->position = ptr->position - 1;
        ptr = ptr->next;
    }
}
