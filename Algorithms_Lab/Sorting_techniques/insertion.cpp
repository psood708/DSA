#include<bits/stdc++.h>
using namespace std;
void InsertionSort( int arr[],int length){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int key,num;
    for(int i =1;i<length;i++){
        key = arr[i];
        num = i-1;
        while(arr[num]>key && num>=0){
            arr[num+1] = arr[num];
            num-=1;
        }
        arr[num+1] = key; 
    }
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
}
void SelectionSort(int arr[], int len)
{
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < len; i++)
    {
        int min_ele = arr[i];
        int min_idx = 0;
        int temp = 0;
        for (int j = i; j < len; j++)
        {
            if (min_ele > arr[j])
            {      
                min_ele = arr[j];
                min_idx = j;   
            }
        }
        if (min_idx > i)
        {          
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    for(int k=0;k<len;k++){
        cout<<arr[k]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr1[] = {5,1,4,6,3,2};
    int arr2[] = {4,5,1,2,6,3};
    cout<<"We are doing Insertion Sort"<<endl;
    InsertionSort(arr1,6);
    cout<<endl;
    cout<<"We are doing Selction Sort"<<endl;
    SelectionSort(arr2,6);
    cout<<endl;
}

 