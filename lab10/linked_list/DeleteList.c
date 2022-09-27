//
//  DeleteList.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include "node.h"

void DeleteList (node ** head) {
    node* temp;
    while (* head != NULL) {
        temp = *head;
        *head = (* head)->next;
        free(temp);
    }
}
