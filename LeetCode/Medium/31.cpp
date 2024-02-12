#include<bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>& nums) {
    int sz = nums.size();
    int ind = -1;
    for (int i = sz - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(nums.begin(), nums.end());
    } else {
        for (int i = sz - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
}

int main(){
    vector<int> v = {2,7,0,1,1,0,7,1};
    nextPermutation(v);
    cout << "Next Permutation: ";
    for(auto &x:v) cout<<x<<" ";
}