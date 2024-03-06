#include<bits/stdc++.h>
using namespace std;
 int findMin(vector<int>& nums) {
        int low = 0,high = nums.size() -1;
        while(low<high){
            if(nums[low]<=nums[high]) return nums[low];
            int mid = low + (high - low)/2;
             if(nums[low]>nums[mid]){
                high = mid ;
            }
            else if(nums[mid]>nums[high]){
                low = mid+1;    
            }
            else{ low = mid+1 ;}

            if(nums[low]<=nums[high]) return nums[low];
        }

    return nums[0];
}

int main ()
{
     vector<vector<int>> tstcases = {{3,4,5,1,2},{4,5,6,7,0,1,2},{11,13,15,17},{3,1,2},{1}};
     vector<int> ans = {1,0,11,1,1};
     vector<int> user = {};
     for( auto i: tstcases){
        user.push_back(findMin(i));
     }
     for(int i = 0;i<ans.size();i++){
        if(user[i]!=ans[i]){
            cout<<"Test Case "<<i+1<<": Failed ❌\n";
            cout<<"Output: "<<user[i]<<endl;
            cout<<"Expected Output: "<<ans[i]<<endl;
        }else{
            cout<<"Test Case "<<i+1<<": Passed ✅\n";
            cout<<"Output: "<<user[i]<<endl;
            cout<<"Expected Output: "<<ans[i]<<endl;
        }
     }
     
    return 0;
}