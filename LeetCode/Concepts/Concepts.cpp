#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void printArr(vector<int> arr,int n){
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

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> tmp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<high){
        if(arr[left]<arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }
        else{
            tmp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
            tmp.push_back(arr[left]);
            left++;
        
    }
    while(right<=high){
        tmp.push_back(arr[right]);
        right++;
    }

    for(int i = low;i<=high;i++){
        arr[i] = tmp[i-low];
    }
}

void mergeSort( vector<int> &arr, int low,int high){
        if(low==high) return;
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
}

//quicksort
int partition(vector<int> &arr, int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<= high - 1){
            i++;
        }
        while(arr[j]> pivot && j>=low + 1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }
}
void qs(vector<int> &arr, int low, int high){
    if(low<high){
        int pIx = partition(arr,low,high);
        qs(arr,low,pIx -1);
        qs(arr,pIx+1,high);
    }
}



int main(){
    vector<int> arr={64, 25, 12, 22, 11,56,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArr(arr,size);
    mergeSort(arr,0,size-1);
    printArr(arr,size);


    return 0;   
}