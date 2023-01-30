#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[],int l,int mid,int h){
    int i=l,j=mid+1,k = l;
    int B[h+1];
    while(i<=mid && j<=h){
        if(arr[i]<arr[j]){
            B[k++] = arr[i++];
        }
        else{
            B[k++] = arr[j++];
        }
    }
    for(;i<=mid;i++){
        B[k++] = arr[i];
    }
    for(;j<=h;j++){
        B[k++] = arr[j];
    }
    for(int w=l;w<=h;w++){
        arr[w] = B[w];
    }
}
void mergeSort(int arr[],int n){
    int g,l,h,mid,i;
    for(g = 2;g<=n;g=g*2){
        for(int i =0;i+g-1<n;i=i+g)
        {
            l=i;
            h=i+g-1;
            mid = (l+h)/2;
            Merge(arr,l,mid,h);
        }
    }
    if(g/2<n){
        Merge(arr,0,g/2,n-1);
    }
}
void printArr(int arr[], int len){
    for(int i =0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// Functions for quicksort
void swap(int * &a,int * &b){
   int *t = a;
   a = b;
   b = t;
}
int partition(int arr[],int l,int h){
    int pivot = arr[l];
    int i =l,j=h;
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        
        if(i<j)swap(arr[i],arr[j]);
        
    }while(i<j);
    swap(arr[l],arr[j]);
    return j;
}

void quickSort(int arr[],int l,int h){
    int j;
    if(l<h){
        j = partition(arr,l,h);
        quickSort(arr,l,j);
        quickSort(arr,j+1,h);
    }
}

int main(){
    int arr1[] = {4,2,6,1,12,8,7,0};
    int arr2[] = {8,5,1,7,21,3,9};
    cout<<"Performing Merge Sort for: ";
    printArr(arr1,8);
    mergeSort(arr1,8);
    cout<<"Merge Sorted Array: ";
    printArr(arr1,8);
    cout<<"Performing Quick Sort for: ";
    printArr(arr2,7);
    quickSort(arr2,0,7);
    cout<<"Quick Sorted Array: ";
    printArr(arr2,7);
}


