#include<bits/stdc++.h>
using namespace std;


int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> count;
        int sum1 = 0;
        count[0] = 1;
        int subArraycnt = 0;
        for(int num:nums){
            sum1+=num;
            if(count.find(sum1 - goal) != count.end()){
                subArraycnt +=count[sum1 -goal];
            }
            count[sum1]++;
        }
        return subArraycnt;
    }
int main ()
{
     
    return 0;
}