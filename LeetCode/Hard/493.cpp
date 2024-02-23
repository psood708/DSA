#include<bits/stdc++.h>
using namespace std;
//REverse Pair

long cnt= 0;
void merge(vector<long> &arr, long low, long mid, long high) {
    vector<long> temp; // temporary array
    long left = low;      // starting index of left half of arr
    long right = mid + 1;   // starting index of right half of arr
 

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (long i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
long countPairs(vector<long> &arr,long low ,long high,long mid){
    long right = mid+1;
    long cnt = 0;
    for(long i= low;i<=mid;i++){
        while(right<=high && arr[i] > 2*arr[right]) right++;
        cnt+=(right -(mid+1));
    }
    return cnt;


}
long mergeSort(vector<long> &arr, long low, long high) {
    long cnt =0;
    if (low >= high) return cnt;
    long mid = (low + high) / 2 ;
    cnt+=mergeSort(arr, low, mid);  // left half
    cnt+=mergeSort(arr, mid + 1, high); // right half
    cnt+= countPairs(arr,low,high,mid);
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
long main(){
    vector<long> n ={2,4,3,5,1};
    cout << mergeSort(n,0,n.size()-1);
    return 0;


}