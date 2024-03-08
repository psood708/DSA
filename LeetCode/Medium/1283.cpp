#include<bits/stdc++.h>
using namespace std;

 bool divisor( vector<int> &nm , int mid, int tld){
        int n = nm.size();
        int sum =0;
        for(int i =0;i<n;i++){
            // int res = (nm[i]/mid);
            int res = nm[i]%mid==0 ? nm[i]/mid : (nm[i]/mid) +1;
            sum+=res;
        }
        if(sum<=tld) return true;
        else   return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
     int n =nums.size();
     if (n > threshold) return -1;
     int low = 1;int high = *max_element(nums.begin(), nums.end());
     while(low<=high){
        int mid = low + (high-low)/2 ;
        if(divisor(nums,mid,threshold)) high = mid -1;
        else low = mid + 1;
     }
        
     
    return low;   
    }


int main ()
{
    vector<int> arr = {44,22,33,11,1};
    int limit = 5;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
     
    return 0;
}