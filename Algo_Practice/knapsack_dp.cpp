#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int profit;
};

vector<vector<int>> knapsack(int W_sack, Item arr[], int n){

    vector<vector<int>> dp(n+1,vector<int>(W_sack+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W_sack;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(arr[i-1].weight<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1].weight]+arr[i-1].profit);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    vector<vector<int>> combinations;
    queue<pair<int,int>> q;
    q.push(make_pair(n,W_sack));

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
         
        q.pop();
        if(i==0 || j==0){
            combinations.push_back({});
        }
        else if(dp[i][j]!=dp[i-1][j]){
            vector<vector<int>> sub_combinations=knapsack(j-arr[i-1].weight,arr,i-1);
            for(int k=0;k<sub_combinations.size();k++){
                sub_combinations[k].push_back(i-1);
                combinations.push_back(sub_combinations[k]);
            }
            sub_combinations.clear();
            q.push(make_pair(i-1,j-arr[i-1].weight));
        }
        else{
            q.push(make_pair(i-1,j));
        }
    }

    return combinations;
}

int main(){
    int W = 8;
    Item arr[] = {{0,0},{2,1},{3,2},{4,5},{5,6}};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> combinations=knapsack(W,arr,n);
    for(int i=0;i<combinations.size();i++){
        for(int j=0;j<combinations[i].size();j++){
            cout<<combinations[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
