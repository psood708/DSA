#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums){
    set<int> s1;
    int s1m = accumulate(nums.begin(), nums.end(), 0);
    for (auto i : nums) {
        s1.insert(i);
    }
    int s2m = accumulate(s1.begin(),s1.end(),0);
    return s2m*2 - s1m;
}


int main(){
    vector<int> sm = {1};
    cout << "Single number is: "<<singleNumber(sm)<<endl;
    return 0;
}