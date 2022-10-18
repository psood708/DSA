#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int find_linear(int arr[], int ele, int len){
    for(int i = 0; i<len; i++){
        if(arr[i] == ele){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[4] = {5,2,8,3};
    int num;
    printf("Enter the element you want to find from the array:");
    scanf("%d",&num);
    int k = find_linear(arr,num,4);
    printf("The element %d is at %d index", num,k);
    return 0;
}