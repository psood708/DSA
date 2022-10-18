#include <stdio.h>
int main(){
    int arr[] = {4,6,8};
    //pointer of an array
    int *p = &arr;
    for(int i = 0; i<3; i++){
        printf("Index->%d:: Value:%d\n",i,*(p + i));
    }
    printf("\n");
    //array of pointers
    int *ptr[3];
    for(int i =0; i<3; i++){
        ptr[i] = &arr[i];
    }
    for(int i = 0; i<3;i++){
        printf("Index->%d:: Value:%d\n",i,*ptr[i]);
    }
    return 0;
}
