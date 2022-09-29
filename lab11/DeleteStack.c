//
//  DeleteStack.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//Deletes the stack when exiting
//top: pointer to the top of the stack
void DeleteStack(node** top) {
    node* temp;
    while (*top!=NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }

    printf("\n Goodbye!\n\n");
}
