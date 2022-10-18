#include<stdio.h>

int main(){
    int arr[] = {22,41,59,26,32,76,20,102,53,64,42,33,55};
    int len_arr = sizeof(arr)/sizeof(arr[0]);
    for(int j = 1;j<len_arr;j++){
        int key = arr[j];
        int i = j -1;
        while (i>0 && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;   
        }
        arr[i+1] = key;
        
    }
    for(int k= 0;k<len_arr;k++){
        printf("%d ",arr[k]);
    }
}