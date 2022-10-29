#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;

}*first = NULL;

void create(int A[],int n){
//n is length of array
  struct Node *t,*last;
  //here we have used the first initialized node struct
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  //the next node is done null and will change the value
  first->next = NULL;
  last = first;
//here we have started from 1 as we have created the inital node
  for(int i =1;i<n;i++){
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }

}

void display(struct Node *p){
    //we will have parameter as first
    //this will display nodes
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
//this is recursive display
void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}
void node_count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    printf("\n%d",count);
}
int Rnode_count(struct Node *p){
    //recursions here is costly as more steps more recursion
    if(p==NULL){
             return 0;
    }
    else{
        //man big brains
        return Rnode_count(p->next)+1;
    }
}
int main(){
    int A[] = {3,5,7,10,15};
    create(A,5);
    display(first);
    printf("\n");
    Rdisplay(first);
    node_count(first);
    printf("\n%d",Rnode_count(first)); 
    return 0;
}