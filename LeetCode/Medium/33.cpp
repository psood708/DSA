#include<bits/stdc++.h>
using namespace std;



 int search(vector<int>& nums, int target) {
        //using binary search 
        int low =0,high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;

            if(nums[low]<=nums[mid]){
             if(nums[mid]>=target && nums[low]<=target){
                high = mid-1;
            }
            else{low=mid+1;}
            }
            else {
                  
             if(nums[mid]<=target && nums[high]>=target){
                low = mid+1;
            }
            else{high = mid-1;}
            }
            }
    return -1;
}


    

int main(){
    vector<int> n = {4,5,6,7,0,1,2};
    cout<< search(n,0);
    return 0;
}