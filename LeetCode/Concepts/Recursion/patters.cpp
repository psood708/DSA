#include<bits/stdc++.h>
using namespace std;

// we are gonna do a pattern for 

int pallindrome(int i , string &s){
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-1-i]) return false;
    return pallindrome(i+1,s);
}


// recursion for fibonnacci
int fibonacci(int i){

    if(i<=1) return i;
    int last = fibonacci(i-1);
    int llast = fibonacci(i-2);
    return last+llast;
}

//subsequence

void printsubs(int id,vector<int> &ds,int arr[],int n){
    if(id==n){
        for(auto it:ds) cout<<it<<" ";
        if(ds.size() ==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
   

    // if we pick
    ds.push_back(arr[id]);
    printsubs(id+1,ds,arr,n);
    ds.pop_back();

     // if we don't pick
    printsubs(id+1,ds,arr,n);
    
}

int main ()
{
    string s = "madam" ;
    cout<<pallindrome(0,s)<<endl;  
    cout<<"Printing fibonacci: "<< fibonacci(8)<<endl; 
    //below this is for printing the subsequence
    int arr[] = {3,1,2};
    int n = 3;

    vector<int> ds;
    printsubs(0,ds,arr,n);
    return 0;
}