#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1 ;
    while(low<high){
        int mid = low +(low+high)/2;
        pair<int,int> res;
        if(nums[mid]==nums[mid-1]){
            res.first =  nums[mid];
            res.second = 2;
            high = mid - 1;
        }
        else if(nums[mid] == nums[mid+1]){
            res.first = nums[mid];
            res.second = 2;
            low = mid + 1;
        }
        else {
            res.first = nums[mid];
            res.second = 1;
        }

        if(res.second==1) return res.first;
    }


}
int main ()
{
     vector<int> vec = {1,1,2,3,3,4,4,8,8};
     cout<<singleNonDuplicate(vec);
    return 0;
}