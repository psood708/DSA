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

//inserting a new node
//1.before first node
//2.inserting between any node
//3.inserting after last node

//STEPS
//1.make a first node
//2.put data
//3.point towards first node
//4. move the first to this new node

void insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index<0 || index > node_count(p)){
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    //this condition is if we want to add in start
    if(index==0){
        t->next = first;
        first = t;
    }
    //this condition is when we need to put it elsewhere
    else{
        for(int i =0;i<index-1;i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

//inserting in a sorted linked list
void sorted_insert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    //here we use 3 pointers
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first==NULL){
        first = t;
    }
    else{
        while(p&& p->data<x){
            q = p;
            p = p->next;
        }
        if(p==first){
            t->next = first;
            first = t;

        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

//deleting nodes
//1. deleting first node
//2. deleteing nodes from between
//for deleting nodes from between we need a tail pointer that follows the previos node before the deleted nodes so p->next can be given to the next node
int Delete(struct Node *p, int index){
    struct Node *q;
    int x = -1;
    if(index <1 || index > node_count(p))
      return -1;
    if(index==1){
        q= first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q = p;
            p =p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
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
int node_count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
     return count;
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

//linear searchh
struct Node * search(struct Node *p,int val){
    while(p!=NULL){
        if(val ==p->data){
            return p;
        }
        else{
            p=p->next;
        }
        return NULL;
    }
}
//improving linear searchh
//1.Transposition: here the data is switched with the previous value
//2. Move to Head: here the key value is brought in the start of the linked list this will save time next time we want to search

struct Node * search_two(struct Node *p,int key){
    //About Parameters:
    //First one is node and the key is the value we looking for
    //here we provide a tail pointer (q) that follows our main node pointer 
    struct Node *q = NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            //here p is being moved in the beginning
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    } 
    return NULL;
}

int main(){
    int A[] = {3,5,7,10,15};
    create(A,5);
    display(first);
    printf("\n\n");
    sorted_insert(first,8);
    // insert(first,4,14);
    display(first);
    printf("\nDeleted element is %d",Delete(first,4));
    printf("\n"); 
     display(first);
    // Rdisplay(first);
    // printf("\n%d",node_count(first));
    struct Node *new ;
    //<<<<<>>>>>>>>>>>
    //MOVE to head linear search begins
    //here we see the change in the initial first
    // new = search_two(first,10);
    // printf("\n");
    // display(new);
    // printf("\n");
    // new = search_two(first,5);
    // display(new);
    //<-------------Move to head linear search ends-------->
    // printf("\n%d",Rnode_count(first)); 
    
    return 0;
}