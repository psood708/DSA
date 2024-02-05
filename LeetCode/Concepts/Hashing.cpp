#include<bits/stdc++.h>
using namespace std;

//hashing theory
// we use map and unordered_map in hashing
void cntFreq(int arr[],int n){
    // time complexit - O(N) = space complexity
    unordered_map<int,int> map;
    for(int i =0;i<n;i++){
        map[arr[i]]++;
    }
    for(auto x: map){
        cout<< x.first<<" "<<x.second<<endl;
    }

}

void maxminFreq(int arr[],int n){

    unordered_map<int,int> mpa;
    for(int i =0;i<n;i++){
        mpa[arr[i]]++;
    }
    int maxFreq = 0,minFreq = n;
    int maxEle = 0,minEle = 0;

    for(auto i:mpa){
        int cnt = i.second;
        int elem = i.first;
        if(maxFreq < cnt){
            maxEle = elem;
            maxFreq = cnt;
        }
        if(minFreq > cnt){
            minEle = elem;
            minFreq = cnt;
        }
    }
    cout<<"The higest frequency item is :  "<< maxEle<<endl;
    cout<<"The Lowest frequency item is :  "<< minEle<<endl;


}
int main(){
    // int n;
    // cout<<"Enter the number of enteries: ";
    // cin>> n;
    // int arr[n];
    // for(int i =0;i<n;i++){
    //     cin>> arr[i];
    // }
    // //pre compute
    // map<int,int> mpp;
    // for(int i =0;i<n;i++){
    //     mpp[arr[i]]++;
    // }

    // int q;
    // cin>>q;
    // while(q--){
    //     int numer;
    //     cout<<"Enter a number: ";
    //     cin>>numer;
    //     cout<< mpp[numer] <<endl;
    // }

    // int arr[] = {10,5,10,15,15,5,10,5,15};
    // int n = sizeof(arr) / sizeof(arr[0]);
  
    // return 0;
    int arr[] = {10, 5, 10, 15, 10, 5,23,10,15,4,23,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxminFreq(arr, n);
      cntFreq(arr,n);
    return 0;
 
}