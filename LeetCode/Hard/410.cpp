#include<bits/stdc++.h>
using namespace std;

int noOfElements(vector<int>& nums, int splsum) {
    int ele = 0;
    int smm = 0;
    for (int i =0;i<nums.size();i++){
        if( ( smm+nums[i]) <= splsum){
            smm += nums[i];
        }
        else{
            ele++;
            smm = nums[i];
        }
    }
    return ele;
}



int splitArray(vector<int>& nums, int k) {
     
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid = ( high + low)/2;
        int cntSp = noOfElements(nums,mid);
        if( cntSp > k-1) low = mid +1;
        else high = mid-1;
    }
    return low;
    }
int main ()
{
     vector<int> n = {7,2,5,10,8};
     cout<<splitArray(n,2);
    return 0;
}