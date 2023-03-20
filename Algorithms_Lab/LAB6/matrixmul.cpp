 
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
    A = {{1,4,5},{1,2,1},{3,5,2} };
    B = {{3,2,1},{1,3,2},{2,2,1} };
    // A.push_back(a);
    // B.push_back(b);
    C = matrixMult(A,B);
    cout<<"\n<<<<<<<<<<Final Matrix>>>>>>>>>\n";
    for(int i = 0;i<A.size();i++){
        for(int j =0;j<A.size();j++){
            cout<<C[i][j]<<'\t';
        }
        cout<<endl;
    }

}










// This was just the demo that we did for learning the vectors that we are going to use in the starassen multiplication
// void display(vector<int> &v){
//     for( int i= 0; i<v.size();i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     vector<int> vec1;
//     int element;
//     for(int i = 0;i<4;i++){
//         cout<<"Enter the element to add to this vector: ";
//         cin>>element;
//         vec1.push_back(element);
//     }
//     display(vec1);
//     vector<int> :: iterator iter = vec1.begin(); // this is iteration 
//     vec1.insert(iter+1,566);//this will insert iter at 2nd position
//     display(vec1);
//     return 0;
// }
