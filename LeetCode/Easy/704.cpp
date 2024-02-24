#include<bits/stdc++.h>
using namespace std;

// binary search
int binarySearch(vector<int> &nums,int low,int high,int targ){
    int mid = (low+high)/2;
    if(low>high) return -1;
    if(nums[mid]==targ) return mid;
    else if(targ>nums[mid]) return binarySearch(nums,mid+1,high,targ);
    return binarySearch(nums,low,mid-1,targ);
}



int main(){
    vector<int> n = {-1,0,3,5,9,12};
    int x = binarySearch(n,0,n.size()-1,6);
    string res = (x>-1)?"Target: ":"Not found!!: ";
    cout<<res<<x;
    return 0;
}