#include <stdio.h>
#include <math.h>
int main()
{
    int element = 0;
    float row_avg[3];
    float row,col;
    float col_avg[2];
    int arr1[3][2];
    for(int i=0;i<3;i++){

        row=0;
        for(int j = 0;j<2;j++){
            printf("enter the element [%d] [%d]: ",i,j);
            scanf("%d",&element);
            arr1[i][j] = element;
            row +=element;
            
        }
        row_avg[i] = row/2;
    
    }
    for(int k = 0;k<2;k++){
        col=0;
        for(int l = 0;l<3;l++){
            col += arr1[k][l];
        }
        col_avg[k]=col/3;
    }

    for(int i =0;i<3;i++){
        printf("%0.2f\t",row_avg[i]);
        for(int j =0;j<2;j++){
            printf(" %d ",arr1[i][j]);
        }
        printf("\n");
    }
    for(int k = 0;k<2;k++){
        printf("\t%0.2f ",col_avg[k]);
    }

    return 0;
}