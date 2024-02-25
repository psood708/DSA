#include<bits/stdc++.h>
using namespace std;
 
int firstOcc(vector<int> &nums, int n , int target){
 
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
}
int lastOcc(vector<int> &nums,int n,int target){
   
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
}


 vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first= firstOcc(nums,n,target);
    
        int last = lastOcc(nums,n,target);
        if(first == -1  && last==-1) return {-1,-1};
       
        return {first,last};
    }

 
int main(){
    vector<int> n = {5,7,7,8,8,10};
    int t = 8;
    vector<int> res = searchRange(n,t);
    cout<<"["<<res[0]<<","<<res[1]<<"]";
    return 0;


}