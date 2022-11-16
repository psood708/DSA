#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *first = NULL,*second=NULL,*third=NULL;

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
 
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > 3)
    {
        printf("You have inserted wrong index");
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    // this condition is if we want to add in start
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    // this condition is when we need to put it elsewhere
    else if(index>0 || index < 3)
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    else{
      t->next = NULL;
      p->next = t;
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
void sorted(){

    struct Node *ll,*last;
    third = (struct Node *)malloc(sizeof(struct Node));
    int arr[],j=2 ;

    while(j>0){
        for(int i=0;i<3;i++){

        }
        j--;
    }
    // if(A[0]>B[0]){
    //   third->data = A[0];
    //   third->next = NULL;
    //   last = third;
    // }
    // else {
    //   third->data = B[0];
    //   third->next = NULL;
    //   last = third;
    // }


    for(int i = 1;i<3;i++){
       
       
    }

}

int main(){
    int A[] = {5,10,15};
    int B[] = {2,3,10};
     create1(A,3);
     create2(B,3);
    //  insert(first,0,11);
    //  insert(first,1,4);
    //  insert(first,2,55);
    //  insert(first,3,7);
     display(first);
     printf("\n");
     display(second);
}