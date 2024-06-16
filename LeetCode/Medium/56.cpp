#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> merge(vector<vector<int>> & intervals) {
         int n = intervals.size();
         if(n <= 1) return intervals;
         sort(intervals.begin(),intervals.end());
         vector<vector<int>> res;
         res.push_back(intervals[0]);

         for(int i =1;i<n;i++){
            if(intervals[i][0] < res.back()[1]){
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            } else{
                res.push_back(intervals[i]);
            }
         }
         return res;

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
    vector<vector<int>> n = {{1,5},{3,5},{4,10},{11,13},{12,15},{14,16}};
    vector<vector<int>> mn = merge(n);
    print2dVector(mn);

    return 0;
}