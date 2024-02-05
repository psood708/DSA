//twosum
#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int> &nums,int target){
    
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){

        if(map.find(target-nums[i]) == map.end())
            map[nums[i]] = i;
        else    
            return{map[target-nums[i]],i};
    }
    return{-1,-1};

}

void printArr(vector<int> &nm){
    for(auto i: nm){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> nums={2,7,11,15};
    vector<int> bb = twoSum(nums,22);
    printArr(bb);

    return 0;
}