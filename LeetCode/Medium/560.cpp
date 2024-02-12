#include<bits/stdc++.h>
using namespace std;
//prefix sum
int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1; 
        int preSum = 0,cnt = 0;
        for (int i=0;i<n;i++) {
        preSum+=nums[i];
        int remove = preSum - k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
        }
        return cnt;
}


int main(){
    vector<int> v ={3,2,1,4};
    cout<<subarraySum(v,6);

    return 0;
}

