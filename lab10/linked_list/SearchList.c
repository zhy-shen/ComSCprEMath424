//
//  SearchList.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include "node.h"

//recursive function to search the list, print if found at current node, and stop if no nodes left
//head: node to search at
//key: value to search for
void SearchList (const node* head, const int key) {
    if (head ->value == key) {
        printf(" Key found at Position: %i\n", head -> position );
    }

    if (head ->next == NULL) {
        printf("\n"); return;
    }
    
    SearchList (head ->next ,key);
}
