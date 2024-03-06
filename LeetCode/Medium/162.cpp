#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int ix = 0;
        int flag = 0;
        if(nums.size()==1) return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1]) return 0;
            else return 1;
        }
        for(int i = 1; i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                flag = 1;
                return i;
            }
        }
        int max = nums[0];
        if(flag == 0){
            for(int i =0;i<nums.size();i++){
                if(nums[i]>max){
                    ix = i;
                    max = nums[i];
                }
            }
        }
        return ix;
    }

int main ()
{
    vector<int> n = {1,2,3,5,6,4};
    cout<<findPeakElement(n);    
    return 0;
}