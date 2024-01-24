#include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

struct Item{
    int item_no;
    int weight;
    int profit;
};

bool compare(Item a, Item b){
    double pv1 = (double)a.profit/a.weight;
    double pv2 = (double)b.profit/b.weight;
    return pv1 > pv2;
}

vector<Item> fractionalKnapsack(int W_sack, Item arr[],int n){

 
    vector<Item> resultant;
    double currWeight = 0;
    double finalProfit = 0;
    sort(arr,arr+n,compare);
     //this is from algorithms sorted in descending
    for(int i =0;i<n;i++){
        if(currWeight + arr[i].weight <= W_sack){
            finalProfit += arr[i].profit;
            currWeight+= arr[i].weight;
            resultant.push_back(arr[i]);
        }
        else{
            int remaining_wt = W_sack - currWeight;
            if(remaining_wt > 0){
                finalProfit+= (double)(remaining_wt/arr[i].weight)*arr[i].profit;
                currWeight=W_sack;
                resultant.push_back(arr[i]);
            }
        }
    }
    return resultant;
}
int main(){
    int w = 13;
    Item arr[] = {{1,1,5},{2,3,10},{3,5,15},{4,4,7},{5,1,8}};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<Item> i1 = fractionalKnapsack(w,arr,n);
    cout << i1.size()<<endl;
    for(int i = 0;i<i1.size();i++){
        cout<< i1[i].item_no << " ";
    }
}