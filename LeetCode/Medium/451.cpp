#include<bits/stdc++.h>
using namespace std;
 int findMaxFrequency(int hash[]){
        int maxFreq = 0;
        for(int i =0;i<256;++i){
            maxFreq = max(maxFreq,hash[i]);
        }
        return maxFreq;
    }
    string frequencySort(string s) {
        int hash[256] = {0};
        for(int i =0;i<s.size();i++){
            hash[s[i]]++;
        }
        string result;
        int maxFreq = findMaxFrequency(hash);

        while(maxFreq > 0){
            for(int i=0;i<256;++i){
                if(hash[i] == maxFreq){
                    result.append(hash[i],i);
                }
            }
            maxFreq--;
        }
        return result;
}

int main ()
{

    string s1 = "tree";
    cout<< frequencySort(s1)<<endl;
    return 0;
}