//
//  Print.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include "node.h"

void Print(const int forward , const node* head) {
    if (head == NULL) {
        printf(" List is emtpy.\n\n");
        return;
    }
    
    printf("\n");
    printf(" ---------------------------------------------------\n");
    printf(" |Pos:| Val:     | Address:       | Next:          |\n");
    printf(" ---------------------------------------------------\n");
    
    //whether to use the regular or reverse print function
    switch(forward) {
        case 0:
            ReversePrintList (head);
            break;
        case 1:
            PrintList (head);
            break;
        default:
            printf("\n Error: forward must be 0 or 1.\n");
            printf(" forward = %i\n",forward); exit (1);
    }
    
    printf(" ---------------------------------------------------\n");
}

//changed to print out 8 digit integers with proper spacing
//pos: position in the linked list
//val: value of the node
//head: memory location of current node
//next: memory location of next node in linked list
void PrintLine (const int pos ,const int val, const node* head, const node* next) {
    printf(" |%3i | %08i |%15p |%15p |\n",pos ,val ,head ,next);
}
    
void PrintList (const node* head) {
    PrintLine (head ->position ,head ->value ,head ,head ->next);
    if (head ->next == NULL){
        return;
    }
    
    PrintList (head ->next);
}

void ReversePrintList (const node* head) {
    if (head ->next == NULL){
        PrintLine (head ->position ,head ->value ,head ,head ->next);
        return;
    }
    
    ReversePrintList (head ->next);
    PrintLine (head ->position ,head ->value ,head ,head ->next);
}
