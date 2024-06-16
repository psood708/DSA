#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int M,int V){

        vector<int> dp(V+1,INT_MAX);
        dp[0] = 0;
        for(int i =1;i<=V;++i){
            for(int coin : coins){
                if(coin<=i && dp[i-coin]!= INT_MAX){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }

    return dp[V]==INT_MAX?-1:dp[V];



}




int main ()
{
    
    vector<int> coins =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}