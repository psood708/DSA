#include<stdio.h>
#include<stdlib.h>

int main(){
    //Array of pointers
    int max;
    printf("Enter number of elements you want in array: ");
    scanf("%d",&max);
    int *ptr[max], arr[max];
    for(int i = 0;i<max;i++){
        int ele = 0;
        printf("Enter value for index %d: ",i);
        scanf("%d",&ele);
        arr[i] = ele;
        ptr[i] = &arr[i];
    }
    //now printing values using arrays of pointer
    for(int k =0;k<max;k++){
        printf("Value of index %d is %d.\n",k,*ptr[k]);
    }

    //Pointer to
    int *pt;
    int arr1[max];
    // *pt[] = &arr1[];
    printf("\nNow doing pointer to arrays \n");
    for(int p = 0;p<max;p++){
        printf("Enter value for index %d: ",p);
        scanf("%d",&arr1[p]);
    }
    pt = arr1;
    // printf("%d",*pt);
    for (int s = 0;s<max;s++){
        printf("%d ",pt[s]);
    }

    return -1;
}
