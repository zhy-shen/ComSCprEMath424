//
//  Pop.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

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
