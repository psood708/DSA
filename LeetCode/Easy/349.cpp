#include<bits/stdc++.h>
using namespace std;


 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(),nums1.end());
        set<int> st2(nums2.begin(),nums2.end());
        vector<int> res;
        for(int num:st1){
            if(st2.find(num)!=st2.end()){
                res.push_back(num);
            }
        }
        return res;
    }


int main(){

    vector<int> n1 = {3,6,4,7,2,3,9,1,0,4,7};
    vector<int> n2 = {7,8,1,4};
    vector<int> n3 = intersection(n1,n2);
    cout<<"[";
    for(auto i:n3){
        cout<<i<<" ";
    }
    cout<<"]";
    return 0;
}