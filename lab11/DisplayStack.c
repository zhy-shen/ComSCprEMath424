//
//  DisplayStack.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//prints a visual representation of the stack
//top: pointer to the top of the stack
void DisplayStack(node* top) {
    if (top == NULL) {
        printf(" Stack is emtpy.\n");
        return;
    }

    printf(" ----------------------------------------------\n");
    printf(" |Pos:| Val:| Address:       | Next:          |\n");
    printf(" ----------------------------------------------\n");
    PrintNode(top);
    printf(" ----------------------------------------------\n");
}

void PrintNode(node* top) {
    printf(" |%3i |%4i |%15p |%15p |\n",
    top->position ,top->value,top,top->next);
    
    if (top->next == NULL) {
        return;
    }
    
    PrintNode(top->next);
}
