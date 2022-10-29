#include<stdio.h>
#include<stdlib.h>
struct Student{
    char name[50];
    int age;
}s;

int main(){
    
    struct Student *ptr = &s;
    printf("Enter name: ");
    scanf("%s",&s.name);
    printf("Enter age: ");
    scanf("%d",&s.age);
    printf("%s is %d years old.",(*ptr).name,(*ptr).age);
}