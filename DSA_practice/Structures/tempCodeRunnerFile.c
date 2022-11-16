#include<stdio.h>
#include<stdlib.h>
  struct Organization{
    char org_name[50];
    int org_id;
    struct Employee{
        int emp_id;
        double em_salary;
        char emp_name[50];
    }e[2];
};
int main(){
    struct Organization o1[2] = { };
    int n =0;
    while(n<2){
        printf("Enter Organization Name: ");
        scanf("%s",&o1[n].org_name);
        printf("Enter Organization ID: ");
        scanf("%d",&o1[n].org_id);
        n++;
    }
    for(int i = 0;i<2;i++){
      for(int j =0;j<2;j++){
            printf("%s Employee %d\n",o1[i].org_name,j+1);
            printf("Enter Employee Name: ");
            scanf("%s",&o1[i].e[j].emp_name);
            printf("Enter Id: ");
            scanf("%d",&o1[i].e[j].emp_id);
            printf("Enter Salary:");
            scanf( "%lf",&o1[i].e[j].em_salary);
      }    
    }
    for(int k = 0;k<2;k++){
        printf("\nCompany Name: %s    Company ID: %d \n",o1[k].org_name,o1[k].org_id);
        printf("<----Employee Details---->\n");
        int num = 0;
        while(num<2){
        printf("Name: %s  ID: %d  Salary: %lf\n",o1[k].e[num].emp_name,o1[k].e[num].emp_id,o1[k].e[num].em_salary);
        num++;
        }
    }
    return -1;
}