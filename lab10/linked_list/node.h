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

typedef struct node node;

struct node {
    int position;
    int value;
    node* next;
};

// Functions associated with struct node
int GetNumberOfNodes();
void GenerateList(node ** head ,const int num);
void Print(const int forward ,const node* head);
void PrintList(const node* head);
void ReversePrintList(const node* head);
int GetKey();
void SearchList(const node* head ,const int key);
void DeleteList(node ** head);

#endif /* node_h */
