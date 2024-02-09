#include<bits/stdc++.h>
using namespace std;
// maxsubarray with max sum
void printMaxSubArray(vector<int>& arr){
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
int maxSubArray(vector<int> &nums){
    if(nums.size()==0){
        return 0;
    }
    
    long long max = LONG_MIN;
    long long sum = 0;
    for(int i =0;i<nums.size();i++){
        sum+=nums[i];
        if(max<sum){
            max = sum;
        }
        if(sum<0){
           sum = 0;
        }
    }
    return max;
}




int main(){

    vector<int> kj = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(kj)<<endl;

    return 0;
}