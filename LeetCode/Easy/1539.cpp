#include<bits/stdc++.h>
using namespace std;
 int findKthPositive(vector<int>& arr, int k) {
        int size = arr.size();
        int low = 0, high = size - 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int missing = arr[mid] - (mid+1);
            if(missing<k){
                low = mid + 1;
            }
            else high = mid -1;
        }
        return low+k;
    }
int main ()
{
     vector<int> n ={2,3,4,7,11};
     cout<<findKthPositive(n,5)<<endl;
     return 0;
}