#include<stdio.h>
#include<stdlib.h>


  struct Student{
    char Name[50];
    int roll_no;
    char add[50];
};
int main(){

   struct Student s1 = {};
   printf("Enter your name: ");
   scanf("%s",&s1.Name);
   printf("Enter your roll no.: ");
   scanf("%d",&s1.roll_no);
   printf("Enter your address: ");
   scanf("%s",&s1.add);
   printf("%s has roll no. %d and lives %s",s1.Name,s1.roll_no,s1.add);


    return -1;
}