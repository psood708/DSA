#include<bits/stdc++.h>
using namespace std;
// 3sum


vector<vector<int>> t3eeSum(vector<int> &nums){
    vector<vector<int>> ans;
    int sum;
    sort(nums.begin(), nums.end()); // -2 , 0, 1 , 1, 2
    for(int i=0;i<nums.size();i++){ // 0 - 4
        if(i!=0 && nums[i]==nums[i-1]) continue; 
        int j = i+1;
        int k = nums.size() -1;
        while(j<=k){
            int sum = nums[i] + nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else {
                vector<int> temp ={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;k--;
                while(j<=k && nums[j] == nums[j-1]) j++;
                while(j<=k && nums[k-1]== nums[k]) k--;
            }
        }
    }
    return ans;
}





// vector<vector<int>> threeSumm1(vector<int> &nums){
//     int tsum;
//     vector<int> res ;
//     vector<vector<int>> final ;
//     for(int i = 0;i<nums.size();i++){  
//         if(res.size()<3){
//             res.push_back(nums[i]);
//             tsum+=nums[i];
//         }
//         if(res.size()==3){
//             if(tsum==0){
//                 final.push_back(res);
//             }
//             tsum-=res[0];
//             res.erase(res.begin());
//         }
//     }
//     return final;
// }
void printArr(vector<vector<int>> &mn){
    for(auto i:mn){
        for(auto j:i){
            cout<<j<<" ";
    }
    cout<<" : ";
    }
}

int main(){
    vector<int> jg = {-2,0,1,1,2};
    vector<vector<int>> mn = t3eeSum(jg) ;
    printArr(mn);
    
}