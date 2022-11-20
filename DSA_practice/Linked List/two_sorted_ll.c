#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *first = NULL,*second=NULL,*third=NULL;
//this program is to sort two sorted linked lists

void create2(int A[], int n) 
{
    // n is length of array
      
    struct Node *t, *last;
    // here we have used the first initialized node struct
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    // the next node is done null and will change the value
    second->next = NULL;
    last = second;
    // here we have started from 1 as we have created the inital node
    for (int i = 1; i < n; i++) 
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create1(int A[], int n) 
{
    // n is length of array
    struct Node *t, *last;
    // here we have used the first initialized node struct
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    // the next node is done null and will change the value
    first->next = NULL;
    last = first;
    // here we have started from 1 as we have created the inital node
    for (int i = 1; i < n; i++) 
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void merge_sort_ll1(struct Node *p, struct Node *q){
    //this first method is using an extra linked list (third)
    struct Node *last;
    if(p->data<q->data){
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p && q){
        if(p-> data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last -> next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p){
        last->next = p;
        }
    else{last->next =q;}
}
void display(struct Node *p)
{
    // we will have parameter as first
    // this will display nodes
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(){
   int A[] = {1,3,5,7};
   int B[] = {2,4,6,8,10};
   create1(A,4);
   create2(B,5);
   merge_sort_ll1(first,second);
   display(third);
}