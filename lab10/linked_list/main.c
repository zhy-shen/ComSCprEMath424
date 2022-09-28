//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#include "main.h"

int main () {
    // Declare the head node in my list
    node* head = NULL;
    
    // Set number of nodes and generate a new list
    const int num_nodes = GetNumberOfNodes();
    GenerateList (&head , num_nodes);
    
    // Print list to screen
    Print (1, head); // forward print
    Print (0, head); // reverse print
    
    // Ask for a key, then search list
    if(num_nodes >0) {
        const int key = GetKey ();
        SearchList (head ,key);
    }
    
    // Delete list (free up memory)
    DeleteList (& head);
}
