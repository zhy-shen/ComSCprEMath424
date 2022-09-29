//
//  node.h
//
//
//  Created by Shen, Zhengyi on 9/27/22.
//

#ifndef node_h
#define node_h
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct node node;

struct node {
    int position;
    int value;
    node* next;
};

// Functions associated with struct node
void DeleteStack(node** top);
void DisplayOptions();
void DisplayStack(node* top);
void ExecuteOption(int *option, int *value, node** top);
int Peek(node* top);
void Pop(node** top, int* output);
void PrintNode(node* top);
void Push(const int input, node** top);
void QueryOption(int *command, int **value);
void GetStackSize(node* top, int* stack_size);

#endif /* node_h */
