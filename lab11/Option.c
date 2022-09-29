//
//  Option.c
//  
//
//  Created by Shen, Zhengyi on 9/29/22.
//

#include "node.h"

//takes a command word as input and returns the corresponding option
int QueryOption() {
    printf(" ENTER COMMAND : ");
    
    char entry[30];
    fgets(entry, sizeof entry, stdin);
    entry[strcspn(entry, "\n")] = 0;
    
    //prevents the program from exiting when there is a stray \n
    //from the scanf for the number entry
    if (strlen(entry) < 2) {
        fgets(entry, sizeof entry, stdin);
        entry[strcspn(entry, "\n")] = 0;
    }
    
    //you can now type in the command instead of having to remember the numbers to each command
    if (strcmp(entry, "list") == 0) {
        return 0;
    }
    else if (strcmp(entry, "push") == 0) {
        return 1;
    }
    else if (strcmp(entry, "pop") == 0) {
        return 2;
    }
    else if (strcmp(entry, "peek") == 0) {
        return 3;
    }
    else if (strcmp(entry, "display") == 0) {
        return 4;
    }
    else if (strcmp(entry, "size") == 0) {
        return 5;
    }
    else if (strcmp(entry, "exit") == 0) {
        return 6;
    }
    
    return 6;
}

//Runs the command based on the number
//option: number for the command
//top: pointer to the top of the stack
void ExecuteOption(const int option, node** top) {
    int value;
    switch(option) {
        case 0: // Display available options
            DisplayOptions();
            break;
        case 1: // Enter a new value then push new node to stack
            printf(" Enter value : ");
            scanf("%i", &value);
            Push(value,top);
            break;
        case 2: // Pop top value off of stack
            if (*top!=NULL) {
                Pop(top,&value);
                printf(" Pop value = %i\n",value);
            }
            else{
                printf(" Stack is empty.\n"); }
            break;
        case 3: // Peek at top value on stack
            if((*top)!=NULL) {
                value = Peek(*top);
                printf(" Top value is %i\n",value);
            }
            else {
                printf(" Stack is empty.\n"); }
            break;
        case 4: // Display the entire stack
            DisplayStack(*top);
            break;
        case 5: // Print stack size
            GetStackSize(*top,&value);
            printf(" Stack size is %i\n",value);
            break;
        case 6: // Do nothing here, but this causes code to end
            break;
        default:
            printf("Error: incorrect option. Try again.\n");
            break;
    }
}
