#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *first = NULL,*second=NULL,*third=NULL;

int isSorted(struct Node *p){
    int x = -34423;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
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
    int a[] ={10,20,0,40,50};
    create1(a,5);
    if(isSorted(first)){
        printf("Sorted!");
    }
    else{
        printf("Not sorted!!");
    }
    printf("\n");
    display(first);
    return 0;


}