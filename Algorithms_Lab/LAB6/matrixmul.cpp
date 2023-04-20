 
#include <vector>
#include<bits/stdc++.h>
using namespace std;

//here first we'll make a function that will define the multiplicatoion that we aree goin to perform

//this is done by the regular method with time complexity of O(n^3)
vector<vector<int>> matrixMult(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int size = a.size();
    //here we declaerd a 2d array that will be of size size*size;
    vector<vector<int>> C ( size,vector<int>(size));
    for(int i =0;i<size;i++){
        for(int j  =0;j<size;j++){
            for(int k =0;k<size;k++){
                C[i][j] +=a[i][k]*b[k][j];
            } 
        }
    }
    return C; 
}

int main(){

    vector<vector<int>> A(3,vector<int>(3));
    vector<vector<int>> B(3,vector<int>(3));
    vector<vector<int>> C(3,vector<int>(3));
      cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }  
         cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }  
 
    C = matrixMult(A,B);
    cout<<"\n<<<<<<<<<<Final Matrix>>>>>>>>>\n";
    for(int i = 0;i<A.size();i++){
        for(int j =0;j<A.size();j++){
            cout<<C[i][j]<<'\t';
        }
        cout<<endl;
    }

}










 