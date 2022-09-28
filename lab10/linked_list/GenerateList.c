//
//  GenerateList.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include <time.h>
#include "node.h"

/**
* Node** head: pointer to the head of the linked list
* const int num_nodes: the number of nodes in the linked list
**/
void GenerateList (node ** head , const int num_nodes ) {
    node* temp; srand( time(NULL) );
    
    for (int i=0; i< num_nodes ; i++) {
        temp = (node *) malloc(sizeof(node));
        
        //get 8 digit numbers to put in linked list (student id?)
        int value2 = rand () % 100000000;
        if (value2 < 10000000) {
            value2 = (value2 + 99999999) % 100000000;
        }
        
        //set the value to the 8 digit number
        temp ->value = value2;
        temp ->position = 0;
        printf("%10i",temp ->value);
    
        if (* head == NULL) {
            *head = temp;
            (* head)->next = NULL;
        }
        
        else {
            temp ->next = *head;
            *head = temp;
        }
    }
    
    printf("\n");
    
    node* ptr = *head; int pos = 1;
    while(ptr != NULL) {
        ptr ->position = pos;
        pos = pos +1;
        ptr = ptr ->next;
    }
}
