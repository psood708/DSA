#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
        int leng1 = s.length();
        int leng2 = t.length();
        if( leng1 != leng2 ) return false;
        unordered_map<char,char> cmp;
        unordered_map<char,bool> used;
        for(int i = 0;i<leng1;i++){
            if(cmp.count(s[i])){
            if(cmp[s[i]] != t[i]) return false;
            }
            else{
                if(used[t[i]]) return false;
                cmp[s[i]] = t[i];
                used[t[i]] = true;
            }
        }
        return true;

    }


int main ()
{
    string s1 = "egg";
    string s2 ="add";;
    cout << isIsomorphic(s1,s2)<<endl;
    return 0;
}