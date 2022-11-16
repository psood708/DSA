#include<stdio.h>

void swap(int *a, int *b){
     //this swap will change their original value i.e pointer
     int *ptr1;
     ptr1 = *a;
     *a = *b;
     *b = ptr1;
     printf("Value at A: %d\nValue at B: %d",*a,*b);
}
int main(){
    int a,b;
    printf("Enter the value for a and b: ");
    scanf("%d %d",&a,&b);
    printf("\nValue at a: %d\nValue at b: %d\n",a,b);
    swap(&a,&b);
    printf("\nValue at a: %d\nValue at b: %d",a,b);
     
}