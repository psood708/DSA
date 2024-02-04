//move zeroes
#include<bits/stdc++.h>
using namespace std;
void printArr(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}
void moveZeroes(vector<int> &nums){
    int sz = nums.size();
        if(sz==0)
            return;
        vector<int> temp;
        int count = 0;
        for(int i =0;i<sz;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
            else{
                count++;
            }
        }
        printArr(temp);
        cout<<endl;
        cout<<count<<endl;
        for(int i = 0;i<sz-count;i++){
                nums[i] = temp[i];
        }
        for(int i =temp.size();i<sz;i++){
            nums[i] = 0;
        }
      
        cout<<endl;
}
 

int main(){
    vector<int> k = {0,1,0,3,13};
    printArr(k);
    cout<<endl;
    moveZeroes(k);
    printArr(k);
    return 0;
}