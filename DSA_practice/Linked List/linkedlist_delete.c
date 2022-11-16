#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int A[], int n)
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
int Delete(struct Node *p, int index,int len){
    struct Node *q;
    int x = -1;
    if(index <1 || index > len)
      return -1;
    if(index==1){
        //this is for first element
        q= first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else{
        //this is for any index except 1st index
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


void insert(struct Node *p, int index, int len, int x)
{
    struct Node *t;
    if (index < 0 || index > len)
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
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
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

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    printf("\n");
    // Rdisplay(first);
    insert(first, 4, 5, 11);
    display(first);
   printf("\nWe deleted the value: %d\n",Delete(first,4,5)) ;
   display(first);
    return 0;
}