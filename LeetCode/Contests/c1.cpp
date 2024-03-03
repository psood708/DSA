#include<bits/stdc++.h>
using namespace std;
 

int minOperations(vector<int>& nums, int k) {
    int cnt=0;
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());
    for(int i =nums.size()-1;i>0;i--){
        if(nums[i] < k){
            nums.pop_back();
            cnt++;
        }
    }
    return cnt;




}


int main(){
    vector<int> nm = {2,11,10,1,3};
    cout<<minOperations(nm,10);
    return 0;
}