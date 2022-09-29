//
//  main.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//Main Program
int main() {
    node* top = NULL;
    int option = 0;
    
    //QueryOption now takes a work instead of the number for the command
    //should make it easier to use and not have to remember the numbers
    while(option != 6) {
        ExecuteOption(option ,&top);
        printf("\n");
        option = QueryOption();
    }

    DeleteStack(&top);
    return 0;
}
