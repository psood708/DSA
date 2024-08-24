#include<bits/stdc++.h>
using namespace std;


void name(int i,string s){
    if (i>0)  {
        i--;
        name(i,s);
        cout<<s;   
    }  
}

void linearly(int i){

    if(i>0){
       i--;
       linearly(i);
       cout<<i+1; 
    }

}
 

void sum1(int i ,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    sum1(i-1,sum + i);
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int factorial(int i){
 if(i==0 || i==1) return 1;

 return i*factorial(i-1);

}
void arrayswap(vector<int> &arr,int l,int r){
    if(l>=r){
        swap(arr[l],arr[r]);
        arrayswap(arr,l+1,r-1);
    }
}


void printArray(vector<int> m){
    for(auto i:m){
        cout<<i<<" ";
    }
}

int main ()
{
    //  name(5," Parrth ");
    //  antilinearly(9);
    // cout<<factorial(6);
    vector<int> r = {1,4,5,6,7,9};
    arrayswap(r,0,5);
    printArray(r);
    // sum1(8,0);
    return 0;
}