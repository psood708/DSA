#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*top= NULL;

void push(int x){
    struct Node *t ;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Stack OVERFLOW");
    }
    else{
        t->data = x;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node *p;
    int x= -1;
    if(top==NULL){
        printf("Stack is Empty");
    }
    else{
        p=top;
        top=top->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n ");
}

int main(){
    push(10);
    push(9);
    push(23);
    push(12);
    push(8);
    Display();
    printf("%d",pop());
}