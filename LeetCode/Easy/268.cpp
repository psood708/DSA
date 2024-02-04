#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums){
    int n = nums.size()+1;
    int suma = (n*(n+1))/2;
    int actual_sum = accumulate(nums.begin(), nums.end(), 0);  // Use accumulate for sum
    return suma - actual_sum;  // Correct the subtraction order
}

int main(){
    vector<int> nums = {9, 3, 6, 4, 2, 1, 7, 5};
    cout << "Missing number is " << missingNumber(nums) << endl;
    return 0;
}
