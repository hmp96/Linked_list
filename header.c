#include "header.h"

Node* CreateNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void AddNode(Handler* handler, int dataToFind, int newData)
{
    Node* newNode = CreateNode(newData);

    Node* current = handler->head;

    while (current != NULL) {
        if (current->data == dataToFind) {
            newNode->prev = current;
            newNode->next = current->next;
            current->next = newNode;

            if (newNode->next != NULL) {
                newNode->next->prev = newNode; // newNode의 next가 가리키는 노드의 prev가 newNode를 가리키게 한다.
            }
            else {
                handler->tail = newNode;
            }

            handler->cnt++;
            return;
        }

        current = current->next;
    }

    if (handler->head == NULL) { // 아무 노드도 없는 경우,
        handler->head = newNode;
        handler->tail = newNode;
    }
    else { // 기존 노드의 맨뒤에 추가
        newNode->prev = handler->tail;
        handler->tail->next = newNode;
        handler->tail = newNode;
    }

    handler->cnt++;
}

bool FindNode(Handler* handler, int num)
{
    Node* current = handler->head;

    int cnt = 0;

    while (current != NULL) {
        if (current->data == num) {
            printf("위치를 찾는 데이터 : %d, 인덱스 위치 : [%d]\n\n", current->data, cnt);
            return true;
        }
        current = current->next;
        cnt++;
    }

    printf("해당 인덱스를 찾지 못했습니다. %d \n\n", num);
    return false;
}

void SwapNodeData(Node* node1, Node* node2) //bubble
{
    int tmp;
    tmp = node1->data;
    node1 -> data = node2 -> data;
    node2 -> data = tmp;
}

void BubbleSortNode(Handler *handler)
{
    if (handler->head == NULL || handler->head->next == NULL) {
        return;
    }

    Node *cur = handler->head;

    int size = handler->cnt;

    for (int i = 0; i < size; i++) {
        cur = handler->head; // 리스트의 맨 앞으로 이동
        if (cur->next == NULL) {
            break;
        }
        for (int j = 0; j < size - 1 - i; j++) {
            if (cur->data > cur->next->data) {
                SwapNodeData(cur, cur->next);
            }
            cur = cur->next;
        }
    }
}

void RemoveNode(Handler* handler, int data)
{
    Node* tmp = handler->head;

    while (tmp != NULL && tmp->data != data) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("%d 데이터는 리스트 안에 없습니다.\n", data);
        return;
    }

    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    }
    else {
        handler->head = tmp->next;
    }

    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }
    else {
        handler->tail = tmp->prev;
    }

    free(tmp);
    handler->cnt--;
}

void FreeNode(Handler* handler)
{
    Node* current = handler->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    handler->head = NULL;
    handler->tail = NULL;
    handler->cnt = 0;

    printf("할당 해제 완료\n");
}

void DumpList(Handler* handler)
{
    Node* current = handler->head;
    while (current != NULL) {
        printf("data : %d, ", current->data);
        printf("prev ptr : %p, ", current->prev);
        printf("next ptr : %p", current->next);

        current = current->next;

        if (current != NULL) {
            printf("\n || \n");
            printf(" || \n");
        }
    }
    printf("\n");
}