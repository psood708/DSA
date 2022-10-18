#include<stdio.h>
#include<stdlib.h>

int find_binary(int arr[], int ele, int len){
     int l = 0, h = len - 1, mid = (l+h)/2;
     while(l!=h){
        mid = (l+h)/2;
        if(arr[mid] == ele){
            return mid;
        }
        if(ele<arr[mid]){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
     }
     return -1;
     
}
int main(){

    int arr[7] = {3,5,8,9,23,26,44};
    int num;
    printf("Enter the element you want to find from the array:");
    scanf("%d",&num);
    int k = find_binary(arr,num,7);
    printf("The element %d is at %d index", num,k);
    return 0;
}
