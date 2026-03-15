#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;    //指针域嵌套，
}Node;

Node* initLsit()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> data = 0;
    head -> next = NULL;
    return head;
}

int insertHead(Node* L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p -> data = e;
    p -> next = L -> next;
    L -> next = p;
    return 1;
}

Node* get_tail(Node* L)
{
    Node *p = L;
    while(p -> next)
    {
        p = p -> next;
    }
    return p;
}

Node* insertTail(Node* L, ElemType e)
{
    Node *tail = get_tail(L);
    Node *p = (Node*)malloc(sizeof(Node));
    p -> data = e;
    p -> next = NULL;
    tail -> next = p;
    return L;
}

int insertNode(Node* L, int pos, ElemType e)
{
    Node *p = L;
    int i = 0;
    while(p && i < pos)
    {
        p = p -> next;
        i++;
    }
    if(!p || i > pos)
        return 0;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = e;
    newNode -> next = p -> next;
    p -> next = newNode;
    return 1;
}

int deleteNode(Node* L, int pos)
{
    Node *p = L;
    int i = 0;
    while(p -> next && i < pos)
    {
        p = p -> next;
        i++;
    }
    if(!p -> next || i > pos)
        return 0;
    Node *temp = p -> next;
    p -> next = temp -> next;
    free(temp);
    return 1;
}

void freeList(Node* L)
{
    Node *p = L;
    while(p)
    {
        Node *temp = p;
        p = p -> next;
        free(temp);
    }
}

int listLength(Node* L)
{
    Node *p = L -> next;
    int len = 0;
    while(p)
    {
        len++;
        p = p -> next;
    }
    return len;
}

void listNode(Node* L)
{
    Node *p = L -> next;
    while(p)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int FindNodeFastSlow(Node* L, int k)
{
    Node *fast = L -> next;
    Node *slow = L -> next;
    for(int i = 0; i < k; i++)
    {
        fast = fast -> next;
    }
    while (fast != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    return slow -> data;
}

int main()
{
    Node *list = initLsit();
    insertTail(list, 10);
    insertTail(list, 20);
    insertTail(list, 30);
    listNode(list);
    printf("The first element is: %d\n", list -> next -> data);
    printf("The Last element is: %d\n", get_tail(list) -> data);
    return 1;
}

