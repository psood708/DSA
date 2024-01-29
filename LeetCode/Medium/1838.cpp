#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k)
{

    unordered_map<int, int> mp; // to store the frequency of elements
    for (auto i : nums)
    {
        mp[i]++;
    }
    //soltuion approach
    sort(nums.begin(),nums.end());
    int left = 0;
    int maxFreq = 0;
    long long sum = 0;

    for(int right =0;right<nums.size();++right){
        sum+=nums[right];
        while((long long)nums[right]*(right-left +1) > sum + k){
            sum-=nums[left];
            ++left;
        }
        maxFreq = max(maxFreq,right - left +1);
    }
    // }
    // int maxEle ;
    // for (auto i : mp)
    // {
    //     int cnt = i.second;
    //     if (cnt > maxFreq)
    //     {
    //         maxFreq = cnt;
    //         maxEle = i.first;
    //     }
    // }
    // for (auto j:mp){
    //     int ele = j.first;
    //     k = (k-maxEle+ele);
    //     if(k>0){
    //         maxFreq++;
    //     }else{
    //         break;
    //     }

    // }
    return maxFreq;
}

int main()
{
    vector<int> vm = {3,9,6};
    cout << "The maximum frequency is " << maxFrequency(vm, 2)<<endl;

    return 0;
}