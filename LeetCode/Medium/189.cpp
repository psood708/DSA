#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k){
    int sz = nums.size();
    if(sz==0)
        return;
    k%=sz;
    if(k>sz)
        return;
    vector<int> temp;

     for(int i = sz - k; i < sz; i++){
        temp.push_back(nums[i]);
    }

     for(int i = sz - k - 1; i >= 0; i--){
        nums[i + k] = nums[i];
    }

     for(int j = 0; j < temp.size(); j++){
        nums[j] = temp[j];
    }
}

void printArr(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main(){
    vector<int> g = {-1, -100, 3, 99};
    
    cout << "Original array: ";
    printArr(g);
    cout << endl;

    int k = 2;
    rotate(g, k);

    cout << "Rotated array by " << k << " positions: ";
    printArr(g);

    return 0;
}
