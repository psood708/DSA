#include<bits/stdc++.h>
using namespace std;

bool ans(vector<int> &piles, int mid , int hours){
    int an = 0;
    for(int i =0;i<piles.size();i++){
        an+= (piles[i]/mid) + (piles[i]%mid ==0?0:1);
    }
    return an<=hours;
}



int minEatingSpeed(vector<int>& piles, int h) {
    // new for sum
    long int l = 1, r = 1000000000;
    while(l<=r){
        long mid = l + (r-l)/2;
        if(ans(piles,mid,h)){
            r = mid;
        }
        else l = mid+1;
    }
    return l;
 
}


int main ()
{
    vector<int> bnana = {30,11,23,4,20};
    cout<<minEatingSpeed(bnana, 5);
    return 0;
}

