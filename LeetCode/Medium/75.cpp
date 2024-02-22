#include<bits/stdc++.h>
using namespace std;

// here we'll be using the DNF( Dutch national Flag method)
// we have 3 rules here , we;ll declare low mid and high
// more details in my notebook

void sortColors(vector<int> &nums){
   int sz = nums.size();
   int low = 0,mid=0,high=sz-1;
   while(mid<=high){
    if(nums[mid]==0){
        swap(nums[low],nums[mid]);
        low++;
        mid++;
    }
    else if(nums[mid]==1){
        mid++;
    }
    else if(nums[mid]==2){
        swap(nums[mid],nums[high]);
        mid++;
        high--;
    }
   }
   
}


void printVector(vector<int> &nums){
    cout<<"[";
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<"]";
}
int main(){

    vector<int> n = {2,0,2,1,1,0};
    printVector(n);
    sortColors(n);
    printVector(n);
    return 0;
}