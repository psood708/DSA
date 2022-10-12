#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct stack{
    int size;
    int top;

};
 
// void Display(struct stack st);
void push(struct stack *st,char x[],char ele);
char pop(struct stack *st,char x[]);
bool isEmpty(struct stack *st);
// bool isFull(struct stack st);
bool prcd(char a,char b);
int main(){
     struct stack *stack1 = (struct stack *)malloc(sizeof(struct stack));
     char s[50];
     printf("Enter infix equation: ");
     gets(s);
     stack1->size = strlen(s);
     char post[strlen(s)];
     for( int i =0;i<strlen(s);i++){
        char c = s[i];
        if(c=='+'||c=='-'||c=='*'||c=='/' || c=='(' || c==')'||c=='$'||c=='^'){
           if(c==')'){
            //have to declare something
            char n='o';
             while(n!='('){
                 n = pop(stack1,post);
                 if(n=='('){
                    continue;
                 }
                 printf("%c",n);
             }            
           }
           else{
            while(!isEmpty(stack1) && prcd(post[stack1->top],c)){
                char new_1 = pop(stack1,post);
                printf("%c",new_1);
            }
            push(stack1,post,c);
           }
        } 
     }
     while(!isEmpty(stack1)){
        char new_1 = pop(stack1,post);
        printf("%c",new_1);
     }
}
 
// void Display(struct stack *st){
//     int i;
//     for(i=st.topli>=0;i--){
//         printf("%d ",st.s[i]);
//     }
//     printf("\n");
// bool isFull(struct stack st){
//     if(st.top==st.size-1){
//         return true;
//     }
//     else
//     return false;
// }
bool isEmpty(struct stack *st){
    if(st->top==-1)
    return true;
    else
    return false;
}
void push(struct stack *st,char x[],char ele){
    if(st->top==st->size-1){
      printf("Stack OverFlow");
    }
    else
    {
        st->top++;
        x[st->top] = ele;
    }
}
char pop(struct stack *st,char x[]){
      if(st->top==-1){
        printf("Stack Underflow");
        
      }
      else{
        st->top--;
         return x[st->top];
      }
}
bool prcd(char a,char b){
      if ((a == '+' || a == '-') && (b == '-' || b == '+'))
        return true;
    else if (a == '+' || a == '-')
        return false;
    else if (a == '-' && (b == '+' || b == '-'))
        return true;
    else if ((a == '/' || a == '*' || a == '%') && (b == '(' || b == '$' || b == '^'))
        return false;
    else if ((a == '/' || a == '*' || a == '%'))
        return true;
    else if ((a == '^' || a == '$') && b == '(')
        return false;
    else if ((a == '^' || a == '$'))
        return true;
    else if (a == '(')
        return false;
    else
        return false;
}