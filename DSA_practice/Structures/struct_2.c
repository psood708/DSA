#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char Name[50];
    int roll_no;
    char add[50];
};
int main()
{
    struct Student s1[5] = {};
    for (int i = 0; i < 5; i++)
    {
        printf("Enter your name Student %d: ",i+1);
        scanf("%s", &s1[i].Name);
        printf("Enter your roll no. Student %d: ",i+1);
        scanf("%d", &s1[i].roll_no);
        printf("Enter your address Student %d: ",i+1);
        scanf("%s", &s1[i].add);
    }
    for (int j = 0; j < 5; j++)
    {
        printf("\n%s has roll no. %d and lives %s", s1[j].Name, s1[j].roll_no, s1[j].add);
    }
    return -1;
}