#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals; 
        sort(intervals.begin(), intervals.end());  

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);  

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                 ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                 ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }

void print2dVector(vector<vector<int>> m){
    for(auto i:m){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> n = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mn = merge(n);
    print2dVector(mn);

    return 0;
}