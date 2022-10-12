//displaying a linked list
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;
//this *first is a global variable of the structure called node


void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }

}
void create(int A[],int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data= A[0];
    first->next = NULL;
    last = first;

    for(i=0;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        first->next=NULL;
        last = t;
    }
}

int main(){
    int a[] ={3,4,5,2,65,12};
    create(a,6);
    Display(first);
    Display(first);
    Display(first);
    Display(first);
    Display(first);

    return 0;
}