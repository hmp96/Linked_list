/*파일 분할*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

int main(void)
{
    Handler listHandler = {NULL, NULL, 0};

    Node* A_node = CreateNode(100); 
    AddNode(&listHandler, 100, A_node->data);

    printf("1. 노드 생성 후 리스트 : \n\n");
    DumpList(&listHandler);
    printf("\n");
    printf("전체 노드의 개수 : %d\n\n", listHandler.cnt);
    printf("==================================================================\n\n");

    AddNode(&listHandler, 100, 200);
    AddNode(&listHandler, 200, 400);
    AddNode(&listHandler, 400, 800);
    AddNode(&listHandler, 800, 700);
    AddNode(&listHandler, 700, 900);
    AddNode(&listHandler, 900, 300);
    AddNode(&listHandler, 300, 500);
    AddNode(&listHandler, 500, 600);

    printf("2. 노드 추가 후 리스트 : \n\n");
    DumpList(&listHandler);
    printf("\n");
    printf("전체 노드의 개수 : %d\n\n", listHandler.cnt);
    printf("==================================================================\n\n");

    BubbleSortNode(&listHandler);
    printf("3. 노드 정렬 후 리스트 : \n\n");
    DumpList(&listHandler);
    printf("\n");
    printf("전체 노드의 개수 : %d\n\n", listHandler.cnt);
    printf("==================================================================\n\n");
    
    FindNode(&listHandler, 700);
    printf("==================================================================\n\n");
    
    RemoveNode(&listHandler, 700);
    printf("3. 노드 삭제 후 리스트 : \n\n");
    DumpList(&listHandler);
    printf("\n");
    printf("전체 노드의 개수 : %d\n\n", listHandler.cnt);
    printf("==================================================================\n\n");

    FreeNode(&listHandler);
    DumpList(&listHandler);
    printf("전체 노드의 개수 : %d\n\n", listHandler.cnt);
    printf("==================================================================\n\n");
    
    return 0;
}