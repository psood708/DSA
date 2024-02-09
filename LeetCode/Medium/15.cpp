#include<bits/stdc++.h>
using namespace std;
// 3sum

vector<vector<int>> threeSumm(vector<int> &nums){
    int tsum;
    vector<int> res ;
    vector<vector<int>> final ;
    for(int i = 0;i<nums.size();i++){  
        if(res.size()<3){
            res.push_back(nums[i]);
            tsum+=nums[i];
        }
        if(res.size()==3){
            if(tsum==0){
                final.push_back(res);
            }
            tsum-=res[0];
            res.erase(res.begin());
        }
    }
    return final;
}
void printArr(vector<vector<int>> &mn){
    for(auto i:mn){
        for(auto j:i){
            cout<<j<<" ";
    }
    cout<<" : "<<endl;
    }
}

int main(){
    vector<int> jg = {-1,0,1,2,-1,-4};
    // we need to sort the given aray
    sort(jg.begin(),jg.end()) ;
    // now call the function and store in variable  
    vector<vector<int>> mn = threeSumm(jg) ;
    printArr(mn);
    
}