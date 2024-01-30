#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void printArr(int arr[],int n){
    for (int i=0;i < n;i++)
        cout << arr[i] << " ";
    cout<<endl;
}
//bubble sort
void bubbleSort(int arr[], int n) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i <= j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void insertSort(int arr[],int n){
    for(int i =0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

void selectSort(int arr[], int n){
    for(int i =0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int arr[]={64, 25, 12, 22, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArr(arr,size);
    insertSort(arr,size);
    printArr(arr,size);
    return 0;
}