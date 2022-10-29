#include <stdio.h>
#include <stdlib.h>
struct Node
{ 
    int data;
    struct Node *next;
} *first = NULL;
typedef struct Node node;
 
void create(int A[], int n)
{
    int i;
    node *t, *last;
    first = (node*)malloc(sizeof(node));
    first->data = A[0];
    first->next = NULL;
    last = first;
 
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display()
{  
    node *temp = first;
    while (temp!= NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
void insertAtFront(int x){
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    t->next = first;
    first = t;
}
void insertAtEnd(int x){
    node *t = (node*)malloc(sizeof(node));
    t->data = x;
    if(first == NULL){
        t->next = first;
        first = t;
    }else{
        node *temp = first;
        while(temp->next!=NULL){
            temp = temp->next;    
        }
        t->next = temp->next;
        temp->next = t;
    }
}
void insertAtPos(int pos, int x){
    if(pos == 0){
        insertAtFront(x);
    }else{
        node *temp = first;
        node *t = (node*)malloc(sizeof(node));
        t->data = x;
        for(int i = 0; i<pos -1; i++){
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
    }
 
}
int main()
{
   
    insertAtEnd(5);
    insertAtFront(11);
    insertAtFront(58);
    insertAtFront(5);
    insertAtPos(1,6);
    insertAtPos(2,15);
    Display(first);
 
    return 0;
}
