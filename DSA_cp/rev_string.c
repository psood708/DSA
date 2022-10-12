#include <stdio.h>  
#include <string.h>  
  
  
int top,stack[100];  
  
void push(char x){  
  
      // Push(Inserting Element in stack) operation  
      if(top == 100-1){  
          printf("stack overflow");  
      }  else {  
          stack[++top]=x;  
      }  
  
}  
  
void pop(){  
    // Pop (Removing element from stack)  
      printf("%c",stack[top--]);  
}  
  
  
int main()  
{  
   char str[50];
   gets(str);  
   int len = strlen(str);  
   int i;  
  
   for(i=0;i<len;i++)  
        push(str[i]);  
  
   for(i=0;i<len;i++)  
      pop();  

  return 0;
} 
