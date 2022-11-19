#include<stdio.h>
#include<stdlib.h>
 struct Node {
    int data;
    struct Node *next;
 }*first=NULL,*second=NULL;
//in this particular program we will concatenate two linked lists

 void create1(int A[],int n){
    struct Node *t,*last;
    //first we need to allocate memory for the linked list
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    //here we need to allocate the rest of the array to linked list
    for(int i =1;i<n;i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
 }
 void create2(int A[],int n){
      struct Node *m ,*last1;
    //first we need to allocate memory for the linked list
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last1 = second;
    //here we need to allocate the rest of the array to linked list
    for(int i =1;i<n;i++){
        m = (struct Node *)malloc(sizeof(struct Node));
        m->data = A[i];
        m->next = NULL;
        last1->next = m;
        last1 = m;
    }
 }
 void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
 }
 //this will concatenate the linked list into one
void concate(struct Node *p){
    p = first;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = second;

}
int main(){
    int A[] = {3,5,1,7,3};
    int B[] = {9,8,6};
    create1(A,5);
    create2(B,3);
    display(first);
    printf("\n");
    display(second);
    printf("\n");
    concate(first);
    display(first);
    printf("\n");
    display(second);
}