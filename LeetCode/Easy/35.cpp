#include<bits/stdc++.h>
using namespace std;

 
int sip(vector<int> &nums,int target){

 
        int lw=0,high=nums.size()-1,mid;
        if(target>nums[high]) return high+1;
        while(lw<high){
            mid = (lw+high)/2;
            if(nums[mid]==target) return mid;
        }
        if(target<nums[mid]) high = mid-1;
        else lw=mid+1;

        return lw;
}
 


int main(){
    vector<int> n = {1,3,5,6};
    cout<<sip(n,2);
    return 0;
}