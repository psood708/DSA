#include<bits/stdc++.h>
using namespace std;
//4sum

vector<vector<int>> fourSum(vector<int> &nums,int target){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());
    for(int i =0;i<n;i++){
        if(i>0 && nums[i]== nums[i-1]) continue;
        for(int j =i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k<l&& nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    }
    return ans;
}


void printArr(vector<vector<int>> &mn){
    for(auto i:mn){
        for(auto j:i){
            cout<<j<<" ";
    }
    cout<<" : ";
    }
}

int main(){

    vector<int> p = {1,0,-1,0,-2,2};
    // printArr(p);
    vector<vector<int>> lp = fourSum(p,0);
    printArr(lp);

    return 0;
}