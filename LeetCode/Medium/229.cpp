#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int threshold = n / 3;

  
    int candidate1 = 0, count1 = 0;
    int candidate2 = 0, count2 = 0;

    for (int num : nums) {
        if (count1 == 0 && num != candidate2) {
            candidate1 = num;
        }
        if (count2 == 0 && num != candidate1) {
            candidate2 = num;
        }

        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

     count1 = count2 = 0;
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    vector<int> result;
    if (count1 > threshold) {
        result.push_back(candidate1);
    }
    if (count2 > threshold && candidate2 != candidate1) {
        result.push_back(candidate2);
    }
    return result;
   }
    


int main(){
    vector<int>
    return 0;
}