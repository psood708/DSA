#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
int stack_arr[6];
int top = -1;
 
struct stack_Linkedlist
{
    int data;
    struct stack_Linkedlist *next;
} *first = NULL;
typedef struct stack_Linkedlist stack_ll;
 
void push_ll(int x){
    stack_ll *t = (stack_ll*)malloc(sizeof(stack_ll));
    t->data = x;
    t->next = first;
    first = t;
}
int pop_ll(){
    if(first == NULL){
        printf("Underflow condition reached!\n");
    }else{
        int ele = first->data;
        stack_ll *temp = first;
        first = first->next;
        free(temp);
        return ele;
    }
}
void display_ll(){
    printf("Stack made by linked list: \n");
    stack_ll *temp = first;
    if(temp == NULL){
        printf("The stack is empty\n");
    }else{
        while (temp!= NULL)
            {
            printf("%d\n", temp->data);
            temp = temp->next;
            }
    }
}
 
void push_arr(int item){
    if(top == 5){
        printf("Overflow condition reached\n");
    }else{
        top++;
        stack_arr[top] = item;
    }
}
int pop_arr(){
    if(top == -1){
        printf("Underflow condition reached!\n");
    }else{
        int ele = stack_arr[top--];
        return ele;
    }
}
void display_arr(){
    printf("Stack made by Array: \n");
    if(top == -1){
        printf("The stack is empty!\n");
    }else{
        for(int i = top; i>=0; i--){
            printf("%d\n",stack_arr[i]);
        }
    }
}
bool isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}
int Top(){
    if(top == -1){
        printf("The stack is empty!\n");
    }else{
        return stack_arr[top];
    }
}
int main(){
    push_ll(4);
    push_ll(11);
    push_ll(6);
    display_ll();
    pop_ll();
    display_ll();
    push_ll(12);
    display_ll();
    return 0;
}
