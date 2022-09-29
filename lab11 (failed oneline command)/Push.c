//
//  Push.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

void Push(const int input, node** top) {
    if (*top == NULL) {
        *top =(node*)malloc(sizeof(struct node));
        (*top)->next = NULL;
        (*top)->value = input;
        (*top)->position = 1;
    }
    else {
        node* temp;
        temp =(node*)malloc(sizeof(struct node));
        temp->next = *top;
        temp->value = input;
        temp->position = 1;
        *top = temp;
        node* ptr = (*top)->next;
        
        while (ptr!=NULL) {
            ptr->position = ptr->position+1;
            ptr = ptr->next;
        }
    }
}
