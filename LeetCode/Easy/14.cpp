#include<bits/stdc++.h>
using namespace std;


 string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res;
        int num = strs.size();
        string prx = strs[0];
        int lng = prx.length();
        for(int i = 1;i<num;i++){
            string stmp = strs[i];
            while(lng > stmp.length() || prx != stmp.substr(0,lng)){
                lng --;
                if(lng ==0){
                    return "";
                }
                prx = prx.substr(0,lng);
            }
        }
        return prx;
    }

int main ()
{
     vector<string> strs = {"flower","flow","floght"};
     cout<<longestCommonPrefix(strs);
    return 0;
}