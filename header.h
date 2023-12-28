#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node* prev;
    struct _node* next;
} Node;

typedef struct _handler {
    Node* head;
    Node* tail;
    int cnt;
} Handler;

Node* CreateNode(int data);
void AddNode(Handler* handler, int dataToFind, int newData);
void SwapNodeData(Node* node1, Node* node2);
void BubbleSortNode(Handler *handler);
void RemoveNode(Handler* handler, int data);
bool FindNode(Handler* handler, int num);
void FreeNode(Handler* handler);
void DumpList(Handler* handler);

#endif