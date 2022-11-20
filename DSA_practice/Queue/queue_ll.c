#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
      printf("FULL");
    else{
        t->data = x;
        t->next = NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}


int dequeue(){
    int x = -1;
    struct Node* t;
    if(front==NULL)
      printf("Empty");
    else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void Display(){
struct Node *p=front;
while(p){
    printf("%d ",p->data);
    p = p->next;
}
printf("\n");
}

int main(){
    enqueue(3);
    enqueue(5);
    enqueue(8);
    enqueue(9);
    enqueue(23);
    enqueue(6);
    Display();
    printf("%d \n",dequeue());
    Display();
    printf("%d \n",dequeue());
    Display();
}