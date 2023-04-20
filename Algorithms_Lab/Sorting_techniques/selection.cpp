#include<bits/stdc++.h>
using namespace std;

void swap( int a, int b)
{
  int t;
  t = a;
  a = b;
  b = t;
}
//selection sort
void SelectionSort(int arr[],int length){
   for(int i =0;i<length;i++){
     for(int j = i+1;j<length;j++){
         if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
         }
     }
   
   }
}
void printArr(int arr[],int n){ 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
  int arr1[] = {3,5,1,6,2,4};
  printArr(arr1,6);
  SelectionSort(arr1,6);
  printArr(arr1,6);
}