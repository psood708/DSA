//21BCP252
//question-2
#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Stack{
    int size;
    int top;
    struct Node **S;
};
void createStack(struct Stack *st,int length){
    st->size = length;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size*sizeof(struct Node *));
}
void push(struct Stack *st,struct Node *ele){
    if(st->top==st->size-1){
        printf("\nSTACK OVERFLOW!!\n");
    }
    else{
        st->top++;
        st->S[st->top] = ele;
    }
}
struct Node *pop(struct Stack *st){
    struct Node *t = NULL;
    if(st->top==-1){
        printf("\nSTACK UNDERFLOW!!\n");
    }
    else{
        t = st->S[st->top--];
        st->top--;
        
    }
    return t;
    
}

int empty(struct Stack *st){
    if(st->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct Stack *st){
    if(st->top==st->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void print(struct Stack *st){
    struct Node *p;
    if(!empty(st)){
        printf("The stack is: ");
        for(int j = 0;j<st->size;j++){
            p = st->S[j];
            printf("%d ",p->data);
        }
        printf("\n");
    }
}
int delMiddle(struct Stack *st){
    int x;
    struct Node *p ,*q;
    p = (struct Node *)malloc(sizeof(struct Node));
    q = (struct Node *)malloc(sizeof(struct Node));
    
    if((st->size % 2)==1){
        //odd
        // q = st->S[0]; //this first
        int middle = (st->size)/2;
         p = st->S[middle];
         q = st->S[middle-1];
         q->next = p->next;
         p->next = NULL;
         x = p->data;
         free(p);
         return x;
    }
    else{
        //even
         q = st->S[0]; //this first
        int middle = (st->size/2)-1;
         p = st->S[middle];
         q = st->S[middle-1];
         q->next = p->next;
         x = p->data;
         p->next = NULL;
         free(p);
         return x;
    }
}
int main()
{
    struct Stack stk;
    int a,b,c;
    struct Node *k;
    k = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number of elements: ");
    scanf("%d",&a);
    createStack(&stk,a);
    for(int i =0;i<a;i++){
        b =0;
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter element for index %d: ",i);
        scanf("%d",&b);
        t->data = b;
        t->next = NULL;
        push(&stk,t);
    }
    print(&stk);
    printf("\nthis is deleted element: %d\n",delMiddle(&stk));
    print(&stk);
    k = pop(&stk);
    printf("Popped element %d\n",k->data);
    return 0;
}
