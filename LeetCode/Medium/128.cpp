#include<bits/stdc++.h>
using namespace std;

    int longestConsecutive(vector<int>& nums) {
        // set<vector<int>> bn = nums;
        int n = nums.size();
        int longest = 1;
        int cnt;
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto i:st){
            if (st.find(i - 1) == st.end()) {
            int cnt = 1;
            int x = i;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

        }



int main(){

    vector<int> vect={100,4,200,1,3,2};
    cout<<"Length of the Longest Consecutive Subsequence is "<<longestConsecutive(vect)<<endl;
    return 0;
}