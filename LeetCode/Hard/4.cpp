#include<bits/stdc++.h>
using namespace std;



void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> tmp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<high){
        if(arr[left]<arr[right]){
            tmp.push_back(arr[left]);
            left++;
        }
        else{
            tmp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
            tmp.push_back(arr[left]);
            left++;
        
    }
    while(right<=high){
        tmp.push_back(arr[right]);
        right++;
    }

    for(int i = low;i<=high;i++){
        arr[i] = tmp[i-low];
    }
}
void mergeSort( vector<int> &arr, int low,int high){
        if(low==high) return;
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);
        int n = n1+n2;
        int left = (n1+n2+1)/2;
        int low = 0,high =n1;
        while(low<=high){
            int mid1 = (low+high)>>1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2 =nums2[mid2];
            if(mid1 -1 >=0) l1 = nums1[mid1-1];
            if(mid2 - 1 >=0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
            
            else return ((double)(max(l1,l2)+min(r1,r2))) /2.0;
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else low=mid1+1;
         }
        return 0;
    }
int main ()
{
    vector<int> n = {1,2};
    vector<int> n1  = {3,4};
    cout<< findMedianSortedArrays(n,n1)<<endl;
     
    return 0;
}