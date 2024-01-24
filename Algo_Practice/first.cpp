#include<bits/stdc++.h>
using namespace std;


void funcAdd(int m){
    if(m>0){
         
        funcAdd(--m);
        cout<<m<<" ";   
    }
}

int main(){

int m = 10;
funcAdd(m);

}