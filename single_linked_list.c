#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* nextNode;
} Node;

Node* CreateNode(int data);
Node* InsertNode(Node* cur, int data);
void DeleteNode(Node* delete, Node* head);
void FreeNode(Node* head);
void PrintList(Node* head);

int main(void)
{
    Node* listHead = NULL;

    listHead = CreateNode(100);

    printf("1. 노드 생성 후 리스트 : ");
    PrintList(listHead);

    Node* Node3 = InsertNode(listHead, 400);
    Node* Node2 = InsertNode(listHead, 300);
    Node* Node1 = InsertNode(listHead, 200);
    printf("2. 노드 추가 후 리스트 : ");
    PrintList(listHead);

    DeleteNode(Node2, listHead);
    printf("3. 노드 삭제 후 리스트 : ");
    PrintList(listHead);

    FreeNode(listHead);

    return 0;
}

Node* CreateNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode -> data = data;
    newNode -> nextNode = NULL;

    return newNode;
}

Node* InsertNode(Node* cur, int data)
{
    Node* after = cur->nextNode;
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode -> data = data;
    newNode -> nextNode = after;

    cur -> nextNode = newNode;

    return newNode;
}

void DeleteNode(Node* delete, Node* head)
{
    Node* next = head;
    if(delete == head){
        free(delete);
        exit(1);
    }

    while(next){
        if(next -> nextNode == delete){
            next -> nextNode = delete -> nextNode;
        }
        next = next -> nextNode;
    }
    free(delete);
}

void FreeNode(Node* head)
{
    while (head != NULL){
        Node* cur = head;
        head = head->nextNode;
        free(cur);
    }
}

void PrintList(Node* head)
{
    while (head != NULL) {
        printf("%d", head->data);
        head = head->nextNode;

        if (head != NULL){
            printf(" <-> ");
        }
    }
    printf("\n");
}