#include<stdio.h>
#include<stdlib.h>

void lin_search(int arr[],int ele,int len){
    for(int i = 0;i<len;i++){
        if(arr[i]==ele){
            printf("%d is found at index: %d using linear search.\n",ele,i);
        }
    }
     
}
int bin_search(int arr[],int ele,int len){
    int low = 0,high = len-1;
    while(low!=high){
        int mid = (low+high)/2;
        if(ele>arr[mid]){
            low = mid +1;
        }
        else if(ele<arr[mid]){
            high = mid -1;
        }
        else{
         return mid;
        }
    }
    return low;

}

int main(){
  
    int arr[] = {2,4,6,12,15,17,24};
    int length = sizeof(arr)/sizeof(arr[0]);
    lin_search(arr,6,length);
    int ele;
    printf("Which element do you want to find from the array. ");
    scanf("%d",&ele);
    int bin_index = bin_search(arr,ele,length);
    printf("%d is found at index: %d using binary search.\n",ele,bin_index);
      
    return -1;
}