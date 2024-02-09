#include<bits/stdc++.h>
using namespace std;


void rotate(vector<vector<int>> &matrix){
    int sz = matrix.size();
    for (int i=0;i<sz;i++){
        for (int j=0;j<i;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i =0;i<sz;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

void printmtrx(vector<vector<int>>& mtx){
    for(int i=0;i<mtx.size();i++){
        for(int j =0;j<mtx.size();j++){
            cout<<mtx[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
        vector<vector<int>> mtrx = {{1,2,3},{4,5,6},{7,8,9}};
        cout<<mtrx.size();
        rotate(mtrx);
        printmtrx(mtrx);
    return 0;
}   