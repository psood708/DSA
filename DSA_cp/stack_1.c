#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int capacity;
    int top;
    int* array;

};
struct Stack* generateStack(int capacity){
     struct Stack* s1 = (struct Stack*)malloc(sizeof(struct Stack*));
     s1->capacity=capacity;
     s1->top= -1;
     s1->array = (int*)malloc(s1->capacity*sizeof(int));
     return   s1;
};
int isNull(struct Stack* s){
    if(s->top==-1){
        printf("Anna Stack Null!!");
        return 0;
    }
    else
    return 1;

};
int isFull(struct Stack* s){
    if(s->top==s->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct Stack* s,int a){
    if(isFull(s)==1){
      printf("Bhai FUll Hai kya kr raha hai!!");
    }
    else{
        
    }
}
int main(){

  struct Stack* st = generateStack(10);
  printf(isNull(st));
 
  
  
  
}

// #include <stdio.h>
// struct stack{
//     int cap;
//     int top;
//     int *array;
// };
// int main()
// {
//     struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
//     printf("enter number of elements in stack");
//     scanf("%d",&s1->cap);
//     s1->top=-1;
//     s1->array=(int *)malloc(s1->cap *4);
//     push(s1,5);
//     push(s1,6);
//     display(s1);
//     pop(s1);
//     display(s1);
// }

// int isEmpty(struct stack* s1){
//     if (s1->top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isFull(struct stack* s1){
//     if (s1->top==s1->cap-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack* s1,int a){
//     if(isFull(s1)==1){
//         printf("Overflow");
//     }
//     else{
//         s1->top++;
//         s1->array[s1->top]=a;
//     }
// }

// int pop(struct stack* s1){
//     if(isEmpty(s1)==1){
//         printf("Underflow");
//     }
//     else{
//         int c=s1->array[s1->top];
//         s1->array[s1->top]='\0';
//         s1->top=s1->top-1;
//         return c;
        
//     }
// }
// int display(struct stack* s1){
//     for(int i=s1->top;i>=0;i--){
//         printf("%d\n",s1->array[i]);
//     }
// }