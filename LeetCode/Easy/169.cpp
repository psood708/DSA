// majority element 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        pair<int,int> mn= {0,0};
        for(auto i:mp){
            if(i.second > mn.second){
                mn.first = i.first;
                mn.second = i.second; 
            }
        }
        return mn.first;
    }
};