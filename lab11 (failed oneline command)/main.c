//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

int main() {
    node* top = NULL;
    int command;
    int value;
    
    while(command != 6) {
        QueryOption(&command, &value);
        ExecuteOption(&command, &value, &top);
    }

    DeleteStack(&top);
    return 0;
}
